#pragma once

/*
�ĺ����� ������ ���� ����ü

id : �ĺ����� symbol table������ ID
index; �ĺ����� string pool������ ���� ��ġ
length: �ĺ����� ����
hash_code: �ĺ����� �ؽð�
suceess: ���ο� �ĺ��ڷμ� �ɺ� ���̺� ����Ǹ� ���� ó��(1), �� ��(-1)
*/
typedef struct SymbolInfo {
    int id;
    int index;
    int length;
    int hash_code;
    int success;    // 1: ���� ó����, -1: ���� �߻�
} SymbolInfo;
