#include "SymbolInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define STR_LEN_SIZE 15
#define SYM_TABLE_SIZE 100
#define STR_POOL_SIZE 1000
#define HASH_TABLE_SIZE 100
#define TRUE 1
#define FALSE 0


char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];																// ���ڿ� ���� �迭
SymbolInfo symbol_table[SYM_TABLE_SIZE];														// ID, Index, Length, 
int sym_id = 0;																				// symbol table�� ����� ����� ����
int index_start = 0;
extern line_num;

																													

// �ؽ� ���̺� ����
typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	int id;
	HTpointer next;
}HTentry;
HTpointer HT[HASH_TABLE_SIZE];


// �Լ� ����
int process_sym_table(char* identifier);
void update_sym_table(int sym_id, int lineno, const char* type, const char* kind);
void set_param_info(int sym_id, const char* param_str, int count);
void printSymbolTable(void);
int divisionMethod(char* str, int tableSize);
HTpointer lookup_hash_table(int id_index, int hscode);
void add_hash_table(int id, int id_index, int hscode);
void printHashTable(void);
void init_sym_table(void);
void init_hash_table(void);
extern void print_error(int error_num, char* identifier);




int process_sym_table(char* identifier) {

	/* string pool overflow (5) */
	if (index_start + strlen(identifier) + 1 >= STR_POOL_SIZE) {
		print_error(5, identifier);
	}

	strcpy_s(str_pool + index_start, STR_POOL_SIZE - index_start,identifier);


	/* long identifier (2) */
	if (strlen(identifier) > STR_LEN_SIZE) {
		print_error(2, identifier);
	}

	/* symbol table overflow (4) */
	if (sym_id >= SYM_TABLE_SIZE) {
		print_error(4, identifier);
	}


	SymbolInfo* sym = &symbol_table[sym_id];

	// �ؽð� ���
	int hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);


	// �ĺ��� �ߺ� ���� Ȯ��
	HTpointer htp = lookup_hash_table(index_start, hash_value);
	if (htp != NULL) {
		printf("%-7d %-15s %-15s", line_num, "TIDENT",identifier);
		printf(" (already exists) [ST-ID:%d|PoolIdx:%d|Len:%d|Hash:%d]\n", symbol_table[htp->id - 1].id, symbol_table[htp->id - 1].index, symbol_table[htp->id - 1].length, hash_value);

		return symbol_table[htp->id - 1].id;				// �ߺ��� �ɺ��̹Ƿ� ���� ID ��ȯ
	}
	else {
		// �ߺ��� �ƴϸ� �ɺ� ���̺� �߰�
		sym->id = sym_id + 1;
		sym->index = index_start;
		sym->length = (int)strlen(str_pool + index_start);
		sym->hash_code = hash_value;
		sym->lineno = line_num;														// ���� ���� ��ȣ ����
		add_hash_table(sym->id, index_start, hash_value);							// �ؽ� ���̺��� string_pool index�� ����
		sym_id++;
	}

	index_start += strlen(identifier);
	str_pool[index_start++] = '\0';

	return sym->id;														// �ɺ� ���̺� ����� ID ��ȯ
}

/* update_sym_table()
* �ɺ� ���̺��� Ư�� �ɺ��� �Ӽ��� ������Ʈ�ϴ� �Լ�
* 
* Args:
* sym_id - ������Ʈ�� �ɺ��� ID
* lineno - �ɺ��� ���ǵ� ���� ��ȣ
* type - �ɺ��� Ÿ�� (int, float, char ��)
* kind - �ɺ��� ���� (scalar, array, function ��)
*/
void update_sym_table(int sym_id, int lineno, const char* type, const char* kind) {
	if(symbol_table[sym_id - 1].lineno == NULL)
		symbol_table[sym_id - 1].lineno = lineno;										
	strcpy(symbol_table[sym_id - 1].type, type);
	strcpy(symbol_table[sym_id - 1].kind, kind);
}

/* set_param_info()
* �ɺ��� �Լ��� ���, �Լ��� �Ķ���� ������ �����ϴ� �Լ�
* 
* Args:	
* sym_id - �Լ� �ɺ��� ID
* param_str - �Ķ���� ���ڿ� (��: "int a, float b")
* count - �Ķ���� ����
*/
void set_param_info(int sym_id, const char* param_str, int count) {
	strcpy(symbol_table[sym_id - 1].params, param_str);	// �Լ��� �Ķ���� ����
	symbol_table[sym_id - 1].params_count = count;		// �Ķ���� ���� ����
}



/* printSymbolTable()
* �ɺ� ���̺� ��� �Լ�
*
* �Է�: ����
*
* ��ȯ��: ����
*/
void printSymbolTable() {
	printf("\n\nSymbol Table:\n");					
	printf("ID\tIndex\tLength\tSymbol\t\tAttributes\n");
	for (int i = 0; i < sym_id; i++) {
		SymbolInfo* sym = &symbol_table[i];
		printf("%-7d\t%-7d\t%-7d\t%-10s\t", sym->id, sym->index, sym->length, str_pool + sym->index);
		
		// ���� �Ӽ� ���
		printf("line %d, %s %s", sym->lineno, sym->type, sym->kind);

		// �Լ���� �Ķ���� �߰� ���
		if (strcmp(sym->kind, "function") == 0) {
			printf(", params: ");
			if (sym->params_count == 0) { printf("- None -"); }
			else{ printf("%s ", sym->params); }
		}

		printf("\n");
	}
	printf("\n");
}



/* divisionMethod()
* hash code ��� (�����)
*
* �Է�:
* str - �ĺ���
* tableSize - �ؽ� ���̺��� ������
* 
* ��ȯ��: �ĺ����� �ؽ� ���̺� �ε��� ��
*/
int divisionMethod(char* str, int tableSize) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {
		key += (int)*(str + i);
	}

	return key % tableSize;
}



/* lookup_hash_table()
* hash bucket�� ������ �ɹ��� �����ϴ��� ã�� �Լ�(�ؽ� ���̺� �̹� �����ϸ� ������ ��ȯ, ������ NULL ��ȯ)
* 
* �Է�:
* index - ���� string pool ��ġ
* hscode - ���� �Էµ� symbol�� hash code
*
* ��ȯ��:
* HTpointer - ã���� �ϴ� symbol�� �̹� ������ ��� �ش� symbol�� ����� HTpointer ��ȯ
*             ���� ���� NULL ��ȯ
*/
HTpointer lookup_hash_table(int index, int hscode) {										
	char* str = str_pool + index;
	int str_len = strlen(str);
	
	HTpointer entry = HT[hscode];

	while (entry != NULL) {
		int existing_idx = entry->index;
		int existing_len = 0;

		
		while (str_pool[existing_idx + existing_len] != '\0') existing_len++;

		if (existing_len == str_len &&
			strncmp(str_pool + existing_idx, str_pool + index, str_len) == 0) {
			return entry;
		}
		

		entry = entry->next;
	}
	return NULL;																			// �׸��� ã�� ���� ��� NULL ��ȯ
}



/* add_hash_table()
* identifier�� hash codeĭ�� �߰�
* 
* �Է�:
* index - ���� string pool ��ġ
* hscode - ���� �Էµ� symbol�� hash code
*
* ��ȯ��: ����
*/
void add_hash_table(int id, int index, int hscode) {
	// �� �׸� ���� �� �ʱ�ȭ
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		print_error(6, "hashtableoverflow");
		return;
	}

	newEntry->index = index;
	newEntry->id = id;
	newEntry->next = NULL;


	// ���Ḯ��Ʈ �տ��� �߰�
	if (HT[hscode] == NULL) {
		HT[hscode] = newEntry;																// �ؽ� ������ ��������� ù �׸�����
	}
	else {
		newEntry->next = HT[hscode];
		HT[hscode] = newEntry;
	}
}



/* add_hash_table()
* �ؽ� ���̺� ������ ����ϴ� �Լ�
*
* �Է�: ����
*
* ��ȯ��: ����
*/
void printHashTable() {
	printf("\n\nHash Table:\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		if (curr == NULL) {																	// �ؽ� ��Ŷ�� ��� �ִ� �κ��� ������� ����
			continue;
		}

		printf("[%d]: ", i);
		while (curr != NULL) {
			printf("%d -> ", curr->id);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}





/* ���̺� �ʱ�ȭ */
void init_sym_table() {
	int i;
	for (i = 0; i < SYM_TABLE_SIZE; i++) {
		symbol_table[i].id = -1;
		symbol_table[i].index = -1;
		symbol_table[i].length = -1;
		symbol_table[i].hash_code = -1;
		symbol_table[i].lineno = -1;
		symbol_table[i].type[0] = '\0';  // �ڷ��� �ʱ�ȭ
		symbol_table[i].kind[0] = '\0';  // ���� �ʱ�ȭ
		symbol_table[i].params_count = 0; // �Լ��� �Ķ���� ���� �ʱ�ȭ
		symbol_table[i].params[0] = '\0'; // �Լ��� �Ķ���� ���� �ʱ�ȭ
	}
}

void init_hash_table() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HT[i] = NULL;
	}
}