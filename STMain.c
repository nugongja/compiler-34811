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
int sym_id = 0;  // symbol table에 저장된 요소의 개수




// 심볼 테이블 출력 함수
void printSymbolTable() {
	int idx = 0;
	printf("--------- Symbol Table -----------\n");
	printf(" ID\tIndex\tLength\tHashValue\n");
	for (int i = 0; i < sym_id; i++) {
		printf(" %d\t%d\t%d\t%d\n", symbol_table[i][0], symbol_table[i][1], symbol_table[i][2], symbol_table[i][3]);
	}
	printf("----------------------------------\n");
}


// 문자열 키 계산
int calc_key(char* str) {
	int length = strlen(str);
	int key = 0;

	for (int i = 0; i < length; i++) {
		key += (int)*(str + i);
	}

	return key;
}

// 해시 테이블 인덱스값 출력
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
	bool first_char = TRUE; // 첫 글자인지 여부 확인

	result = fopen_s(&fp, "example.txt", "r");
	if (result != 0) {
		printf("파일을 열수 없습니다(%d)\n", result);
		return -1;
	}

	int err_flag = FALSE;
	do {
		c = fgetc(fp);

		if (index_next >= sizeof(str_pool) - 1) {
			printf("오류: 문자열 버퍼 크기 초과\n");
			break;
		}

		if ((strchr(separators, c) != NULL) || c == EOF) {  // 처리 불가능한 문자이거나, 마지막 문자일 경우
			if (index_next > index_start) {   // 빈 문자열 출력 방지
				str_pool[index_next++] = '\0'; // 현재 단어 끝내기

				if (err_flag != TRUE) {
					printf("%s\n", str_pool + index_start);   // 정상적인 식별자 출력

					char* str = str_pool + index_start;

					// 해시값 계산
					int key = calc_key(str);
					int hash = divisionMethod(key, HASH_TABLE_SIZE);

					// 심벌 테이블에 넣기
					symbol_table[sym_id][0] = sym_id + 1;
					symbol_table[sym_id][1] = index_start;
					symbol_table[sym_id][2] = index_next - index_start - 1;   // -1 : 마지막 null 빼줌
					symbol_table[sym_id][3] = hash;
					sym_id++;
		
					index_start = index_next;  // 다음 단어의 시작 위치 저장
				}
				else {
					printf("Error - Invalid identifire (%s)\n", str_pool + index_start);
					index_next = index_start; // 에러 발생 시 현재 위치 초기화
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
		else { // 숫자가 나왔을 때
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

