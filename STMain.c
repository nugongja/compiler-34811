#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE 100
#define STR_POOL_SIZE 500
#define HASH_TABLE_SIZE 10
#define TRUE 1
#define FALSE 0

char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
char symbol_table[SYM_TABLE_SIZE][4];  // ID, Index, Length, Hash_idx
int sym_id = 0;  // symbol table�� ����� ����� ����




// �ɺ� ���̺� ��� �Լ�
void printSymbolTable() {
	int idx = 0;
	printf("--------- Symbol Table -----------\n");
	printf(" ID\tIndex\tLength\tHashValue\n");
	for (int i = 0; i < sym_id; i++) {
		printf(" %d\t%d\t%d\t%d\n", symbol_table[i][0], symbol_table[i][1], symbol_table[i][2], symbol_table[i][3]);
	}
	printf("----------------------------------\n");
}


// ���ڿ� Ű ���
int calc_key(char* str) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {
		key += (int)*(str + i);
	}

	return key;
}

// �ؽ� ���̺� �ε����� ���
int divisionMethod(int key, int tableSize) {
	return key % tableSize;
}



int main() {
	FILE* fp;
	int result;
	int c;
	int index_start = 0;
	int index_next = 0;
	int index = 0;
	bool first_char = TRUE; // ù �������� ���� Ȯ��

	result = fopen_s(&fp, "example.txt", "r");
	if (result != 0) {
		printf("������ ���� �����ϴ�(%d)\n", result);
		return -1;
	}

	int err_flag = FALSE;
	do {
		c = fgetc(fp);

		if (index_next >= sizeof(str_pool) - 1) {
			printf("����: ���ڿ� ���� ũ�� �ʰ�\n");
			break;
		}

		if ((strchr(separators, c) != NULL) || c == EOF) {  // ó�� �Ұ����� �����̰ų�, ������ ������ ���
			if (index_next > index_start) {   // �� ���ڿ� ��� ����
				str_pool[index_next++] = '\0'; // ���� �ܾ� ������

				if (err_flag != TRUE) {
					printf("%s\n", str_pool + index_start);   // �������� �ĺ��� ���

					char* str = str_pool + index_start;

					// �ؽð� ���
					int key = calc_key(str);
					int hash = divisionMethod(key, HASH_TABLE_SIZE);

					// �ɹ� ���̺� �ֱ�
					symbol_table[sym_id][0] = sym_id + 1;
					symbol_table[sym_id][1] = index_start;
					symbol_table[sym_id][2] = index_next - index_start - 1;   // -1 : ������ null ����
					symbol_table[sym_id][3] = hash;
					sym_id++;
		
					index_start = index_next;  // ���� �ܾ��� ���� ��ġ ����
				}
				else {
					printf("Error - Invalid identifire (%s)\n", str_pool + index_start);
					index_next = index_start; // ���� �߻� �� ���� ��ġ �ʱ�ȭ
					err_flag = FALSE;
				}
				first_char = TRUE;
			}
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
			if (first_char) {
				first_char = FALSE;
			}
			str_pool[index_next++] = (char)c;
		}
		else { // ���ڰ� ������ ��
			str_pool[index_next++] = (char)c;
			if (first_char) {
				err_flag = TRUE;
				first_char = FALSE;
			}
		}

	} while (c != EOF);

	printSymbolTable();

	fclose(fp);
	return 0;
}

