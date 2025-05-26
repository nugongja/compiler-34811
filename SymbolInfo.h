#pragma once

/*
�ĺ����� ������ ���� ����ü

id : �ĺ����� symbol table������ ID
index; �ĺ����� string pool������ ���� ��ġ
length: �ĺ����� ����
hash_code: �ĺ����� �ؽð�
lineno: �ĺ��ڰ� ����� ���� ��ȣ
type: �ĺ����� �ڷ��� (int, float, char ��)
kind: �ĺ����� ���� (scalar, array, function ��)
params_count: �Լ��� �Ķ���� ���� (�Լ��� ��쿡�� ���)
params: �Լ��� �Ķ���� ���� (�Լ��� ��쿡�� ���, �ִ� 128�� �Ķ���� ����)
*/

typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int lineno;    
    char type[16];  
	char kind[16];  
	int params_count; 
	char params[128]; 
} SymbolInfo;
