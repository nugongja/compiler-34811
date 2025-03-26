#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define STR_LEN_SIZE 15
#define SYM_TABLE_SIZE 100
#define STR_POOL_SIZE 500
#define HASH_TABLE_SIZE 20
#define TRUE 1
#define FALSE 0


char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];																// ���ڿ� ���� �迭
int symbol_table[SYM_TABLE_SIZE][3];														// ID, Index, Length
int sym_id = 0;																				// symbol table�� ����� ����� ����


// �ؽ� ���̺� ����
typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	HTpointer next;
}HTentry;
HTpointer HT[HASH_TABLE_SIZE];


void printSymbolTable(void);
int insertSymbol(int index_start, int index_next);
int calc_key(char* str);
int divisionMethod(int key, int tableSize);
HTpointer lookup_hash_table(int id_index, int hscode);
void add_hash_table(int id_index, int hscode);
void printHashTable(void);




// == main function ==

int main() {
	FILE* fp;
	int result;
	int c;
	int index_start = 0;
	int index_next = 0;
	int index = 0;
	bool first_char = TRUE;																	// ù �������� ���� Ȯ��

	// ���� ����
	result = fopen_s(&fp, "example.txt", "r");
	if (result != 0) {
		printf("������ ���� �����ϴ�(%d)\n", result);
		return -1;
	}

	
	int err_flag = FALSE;																	// �ĺ��ڰ� ��ȿ���� �˻��ϴ� ����
	do {
		c = fgetc(fp);																		// ���ڿ� �ϳ��� �˻�

		if (index_next >= sizeof(str_pool) - 1) {
			printf("����: ���ڿ� ���� ũ�� �ʰ�\n");
			break;
		}

		if ((strchr(separators, c) != NULL) || c == EOF) {									// ���ڿ��� ��
			if (index_next > index_start) {													// �� ���ڿ� ��� ���� (���ڿ��� �����ؼ� index_next > index_start�� ��츸 ó��)
				str_pool[index_next++] = '\0';												// ���� �ܾ� ������

				if (err_flag != TRUE) {
					if (insertSymbol(index_start, index_next)) {							// ���������� �ɺ� ���̺� ����� ��쿡
						index_start = index_next;											// ���� �ܾ��� ���� ��ġ ����
					}
					else {
						index_next = index_start;
					}
				}
				else {
					printf("Error - Invalid identifire (%s)\n", str_pool + index_start);	// ��ȿ���� ���� �ĺ����� ���
					index_next = index_start;												// ���� �߻� �� ���� ��ġ �ʱ�ȭ
					err_flag = FALSE;				
				}
				first_char = TRUE;															// �� ���ڿ� ����
			}
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {			// ��ȿ�� ������ ���
			if (first_char) {
				first_char = FALSE;
			}
			str_pool[index_next++] = (char)c;
		}
		else if ((c >= '0' && c <= '9')) {													// ������ ���
			str_pool[index_next++] = (char)c;
			if (first_char) {																// ���ڰ� �� ó������ ������ ��ȿ���� ���� �ĺ���
				err_flag = TRUE;
				first_char = FALSE;
			}
		}
		else {
			str_pool[index_next++] = (char)c;												// ����, ����, ����, �����ڸ� ������ �ٸ� ����: ������ ����
			err_flag = TRUE;
			first_char = FALSE;
		}
	} while (c != EOF);

	printSymbolTable();
	printHashTable();

	fclose(fp);
	return 0;
}




// == symbol table function ==

/* printSymbolTable()
* �ɺ� ���̺� ��� �Լ�
*
* �Է�: ����
*
* ��ȯ��: ����
*/
void printSymbolTable() {
	printf("\n----------------- Symbol Table -------------------\n");					
	printf(" Name\t\t\tID\tIndex\tLength\n");
	printf("--------------------------------------------------\n");
	for (int i = 0; i < sym_id; i++) {
		printf(" %-16s\t%d\t%d\t%d\n", str_pool+symbol_table[i][1], symbol_table[i][0], symbol_table[i][1], symbol_table[i][2]);
	}
	printf("--------------------------------------------------\n\n");
}

/* insertSymbol()
* �ĺ����� ��ȿ�� �˻� �� �ɺ� ���̺� ����
*
* �Է�:
* index_start - �ĺ����� string pool������ start index
* index_next - �ĺ����� string pool������ ������ index
* 
* ��ȯ��:
* 0(FALSE) - �ĺ����� ���� �ʰ� Ȥ�� �ɺ����̺� �����ϴ� �ĺ����� ��� 0�� ��ȯ
* 1(TRUE) - ���������� �ɺ� ���̺� �ĺ��ڸ� ������ ��� 1�� ��ȯ
*/
int insertSymbol(int index_start, int index_next) {
	char* new_str = str_pool + index_start;
	int new_len = index_next - index_start - 1;

	if (new_len > STR_LEN_SIZE) {															// �ĺ����� ���̴� �ִ� 15��
		printf("Error - Identifier too long (%s)\n", new_str);								
		return FALSE;
	}


	// �ؽð� ���
	int key = calc_key(new_str);
	int hscode = divisionMethod(key, HASH_TABLE_SIZE);


	// �ĺ��� �ߺ� ���� Ȯ��
	HTpointer htp = lookup_hash_table(index_start, hscode);
	if (htp != NULL) {
		printf("%s (Already exists)\n", new_str);
		return FALSE;
	} 
	else {
		printf("%s\n", str_pool + index_start);												// �������� �ĺ��� ���
	}


	// �ߺ��� �ƴϸ� �ɺ� ���̺� �߰�
	symbol_table[sym_id][0] = sym_id + 1;
	symbol_table[sym_id][1] = index_start;
	symbol_table[sym_id][2] = new_len;

	add_hash_table(index_start, hscode);													// �ؽ� ���̺��� string_pool index�� ����
	sym_id++;

	return TRUE;
}




// == hash table function ==

/* calc_key()
* �ĺ����� Ű�� ���
*
* �Է�:
* str - �ĺ���
*
* ��ȯ��:
* key - �ĺ��ڸ� �̷�� ���ڵ��� �������� ��
*/
int calc_key(char* str) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {														
		key += (int)*(str + i);
	}

	return key;
}


/* divisionMethod()
* hash code ��� (�����)
*
* �Է�:
* key - �ĺ����� Ű��
* tableSize - �ؽ� ���̺��� ������
* 
* ��ȯ��: �ĺ����� �ؽ� ���̺� �ε��� ��
*/
int divisionMethod(int key, int tableSize) {
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
void add_hash_table(int index, int hscode) {
	// �� �׸� ���� �� �ʱ�ȭ
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	newEntry->index = index;
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
	printf("\n---------- Hash Table ----------\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		if (curr == NULL) {																	// �ؽ� ��Ŷ�� ��� �ִ� �κ��� ������� ����
			continue;
		}

		printf("[%d] -> ", i);
		while (curr != NULL) {
			printf("%s(String Start Index:%d) -> ", str_pool + curr->index, curr->index);
			curr = curr->next;
		}
		printf("NULL\n");
	}
	printf("--------------------------------\n\n");
}