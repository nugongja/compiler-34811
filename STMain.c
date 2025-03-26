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
char str_pool[STR_POOL_SIZE];																// 문자열 저장 배열
int symbol_table[SYM_TABLE_SIZE][3];														// ID, Index, Length
int sym_id = 0;																				// symbol table에 저장된 요소의 개수


// 해시 테이블 정의
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
	bool first_char = TRUE;																	// 첫 글자인지 여부 확인

	// 파일 열기
	result = fopen_s(&fp, "example.txt", "r");
	if (result != 0) {
		printf("파일을 열수 없습니다(%d)\n", result);
		return -1;
	}

	
	int err_flag = FALSE;																	// 식별자가 유효한지 검사하는 변수
	do {
		c = fgetc(fp);																		// 문자열 하나씩 검사

		if (index_next >= sizeof(str_pool) - 1) {
			printf("오류: 문자열 버퍼 크기 초과\n");
			break;
		}

		if ((strchr(separators, c) != NULL) || c == EOF) {									// 문자열의 끝
			if (index_next > index_start) {													// 빈 문자열 출력 방지 (문자열이 존재해서 index_next > index_start인 경우만 처리)
				str_pool[index_next++] = '\0';												// 현재 단어 끝내기

				if (err_flag != TRUE) {
					if (insertSymbol(index_start, index_next)) {							// 정상적으로 심볼 테이블에 저장된 경우에
						index_start = index_next;											// 다음 단어의 시작 위치 저장
					}
					else {
						index_next = index_start;
					}
				}
				else {
					printf("Error - Invalid identifire (%s)\n", str_pool + index_start);	// 유효하지 않은 식별자인 경우
					index_next = index_start;												// 에러 발생 시 현재 위치 초기화
					err_flag = FALSE;				
				}
				first_char = TRUE;															// 새 문자열 시작
			}
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {			// 유효한 문자인 경우
			if (first_char) {
				first_char = FALSE;
			}
			str_pool[index_next++] = (char)c;
		}
		else if ((c >= '0' && c <= '9')) {													// 숫자인 경우
			str_pool[index_next++] = (char)c;
			if (first_char) {																// 숫자가 맨 처음으로 나오면 유효하지 않은 식별자
				err_flag = TRUE;
				first_char = FALSE;
			}
		}
		else {
			str_pool[index_next++] = (char)c;												// 영어, 숫자, 밑줄, 구분자를 제외한 다른 문자: 무조건 오류
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
* 심볼 테이블 출력 함수
*
* 입력: 없음
*
* 반환값: 없음
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
* 식별자의 유효성 검사 및 심볼 테이블에 삽입
*
* 입력:
* index_start - 식별자의 string pool에서의 start index
* index_next - 식별자의 string pool에서의 마지막 index
* 
* 반환값:
* 0(FALSE) - 식별자의 길이 초과 혹은 심볼테이블에 존재하는 식별자인 경우 0을 반환
* 1(TRUE) - 정상적으로 심볼 테이블에 식별자를 삽입한 경우 1을 반환
*/
int insertSymbol(int index_start, int index_next) {
	char* new_str = str_pool + index_start;
	int new_len = index_next - index_start - 1;

	if (new_len > STR_LEN_SIZE) {															// 식별자의 길이는 최대 15자
		printf("Error - Identifier too long (%s)\n", new_str);								
		return FALSE;
	}


	// 해시값 계산
	int key = calc_key(new_str);
	int hscode = divisionMethod(key, HASH_TABLE_SIZE);


	// 식별자 중복 여부 확인
	HTpointer htp = lookup_hash_table(index_start, hscode);
	if (htp != NULL) {
		printf("%s (Already exists)\n", new_str);
		return FALSE;
	} 
	else {
		printf("%s\n", str_pool + index_start);												// 정상적인 식별자 출력
	}


	// 중복이 아니면 심볼 테이블에 추가
	symbol_table[sym_id][0] = sym_id + 1;
	symbol_table[sym_id][1] = index_start;
	symbol_table[sym_id][2] = new_len;

	add_hash_table(index_start, hscode);													// 해시 테이블에는 string_pool index만 저장
	sym_id++;

	return TRUE;
}




// == hash table function ==

/* calc_key()
* 식별자의 키값 계산
*
* 입력:
* str - 식별자
*
* 반환값:
* key - 식별자를 이루는 문자들의 정수값의 합
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
* hash code 계산 (제산법)
*
* 입력:
* key - 식별자의 키값
* tableSize - 해시 테이블의 사이즈
* 
* 반환값: 식별자의 해시 테이블 인덱스 값
*/
int divisionMethod(int key, int tableSize) {
	return key % tableSize;
}


/* lookup_hash_table()
* hash bucket에 동일한 심벌이 존재하는지 찾는 함수(해시 테이블에 이미 존재하면 포인터 반환, 없으면 NULL 반환)
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 반환값:
* HTpointer - 찾고자 하는 symbol이 이미 존재할 경우 해당 symbol이 저장된 HTpointer 반환
*             없을 경우는 NULL 반환
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
	return NULL;																			// 항목을 찾지 못한 경우 NULL 반환
}



/* add_hash_table()
* identifier의 hash code칸에 추가
* 
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 반환값: 없음
*/
void add_hash_table(int index, int hscode) {
	// 새 항목 생성 및 초기화
	HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
	if (newEntry == NULL) {
		printf("메모리 할당 실패\n");
		exit(1);
	}

	newEntry->index = index;
	newEntry->next = NULL;


	// 연결리스트 앞에서 추가
	if (HT[hscode] == NULL) {
		HT[hscode] = newEntry;																// 해시 슬롯이 비어있으면 첫 항목으로
	}
	else {
		newEntry->next = HT[hscode];
		HT[hscode] = newEntry;
	}
}


/* add_hash_table()
* 해시 테이블 내용을 출력하는 함수
*
* 입력: 없음
*
* 반환값: 없음
*/
void printHashTable() {
	printf("\n---------- Hash Table ----------\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		HTpointer curr = HT[i];
		if (curr == NULL) {																	// 해시 버킷의 비어 있는 부분은 출력하지 않음
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