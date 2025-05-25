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
param_count: �Լ��� �Ķ���� ���� (�Լ��� ��쿡�� ���)
param_types: �Լ��� �Ķ���� ���� (�Լ��� ��쿡�� ���, �ִ� 5�� �Ķ���� ����)
*/

typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int lineno;    
    char type[10];  
	char kind[10];  
	int param_count; 
	char param_types[5][10]; 
} SymbolInfo;
