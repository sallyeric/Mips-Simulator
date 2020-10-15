#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string AddBinary(string a, string b)
{
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--;
        j--;
    }
    return result;
}

string CharToBin(char c)
{
    // string s3 = "00000000000000000000000000000000";
    // cout << s2[0] << '\n';
    // cout << s2[1] << '\n';
    // cout << s2[2] << '\n';
    // cout << s2[3] << '\n';
    // return s2;
    switch (toupper(c))
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    }
    // cout << '\n'
    //      << c << '\n';
    return 0;
}

string BinToChar(string c)
{
    if (c == "0000")
        return c = "0";
    else if (c == "0001")
        return c = "1";
    else if (c == "0010")
        return c = "2";
    else if (c == "0011")
        return c = "3";
    else if (c == "0100")
        return c = "4";
    else if (c == "0101")
        return c = "5";
    else if (c == "0110")
        return c = "6";
    else if (c == "0111")
        return c = "7";
    else if (c == "1000")
        return c = "8";
    else if (c == "1001")
        return c = "9";
    else if (c == "1010")
        return c = "a";
    else if (c == "1011")
        return c = "b";
    else if (c == "1100")
        return c = "c";
    else if (c == "1101")
        return c = "d";
    else if (c == "1110")
        return c = "e";
    else if (c == "1111")
        return c = "f";
    return 0;
}

int BinToDec(string reg)
{
    string num = reg;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

void BinToImm(string imm)
{
    // 일단 -1
    int i = imm.size() - 1;
    // a[i] = 1 이면, 마지막 자리 0 되고 끝!
    if (imm[i] == '1')
    {
        imm[i] = '0';
    }
    // a[i] = 0 이면, 1 나올 때까지 1 넣고 해당 자릿수는 0
    // if (imm[i] == '0')
    else
    {
        while (imm[i] != '1')
        {
            imm[i] = '1';
            i--;
        }
        imm[i] = '0';
    }
    // cout << imm << " ";
    int j = 0;
    for (j = 0; j < 16; j++)
    {
        if (imm[j] == '0')
            imm[j] = '1';
        else
            imm[j] = '0';
    }
    // cout << imm << " ";
    int result = BinToDec(imm) * (-1);
    cout << result;
}

// R: rs rt rd sa
void rdrsrt(string reg)
{
    string rd = "";
    string rs = "";
    string rt = "";
    string sa = "00000";
    for (int i = 0; i < 5; i++)
    {
        rs += reg[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 15; i++)
    {
        rd += reg[i];
    }
    int rdDec = BinToDec(rd);
    cout << "$" << rdDec;
    cout << ", ";
    cout << "$" << rsDec;
    cout << ", ";
    cout << "$" << rtDec;
}

void rsrt(string reg)
{
    string rd = "00000";
    string rs = "";
    string rt = "";
    string sa = "00000";
    for (int i = 0; i < 5; i++)
    {
        rs += reg[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg[i];
    }
    int rtDec = BinToDec(rt);
    cout << "$" << rsDec;
    cout << ", ";
    cout << "$" << rtDec;
}

void rdrs(string reg)
{
    string rd = "";
    string rs = "";
    string rt = "00000";
    string sa = "00000";
    for (int i = 0; i < 5; i++)
    {
        rs += reg[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 10; i < 15; i++)
    {
        rd += reg[i];
    }
    int rdDec = BinToDec(rd);
    cout << "$" << rdDec;
    cout << ", ";
    cout << "$" << rsDec;
}

void rs(string reg)
{
    string rd = "00000";
    string rs = "";
    string rt = "00000";
    string sa = "00000";
    for (int i = 0; i < 5; i++)
    {
        rs += reg[i];
    }
    int rsDec = BinToDec(rs);
    cout << "$" << rsDec;
}

void rd(string reg)
{
    string rd = "";
    string rs = "00000";
    string rt = "00000";
    string sa = "00000";
    for (int i = 10; i < 15; i++)
    {
        rd += reg[i];
    }
    int rdDec = BinToDec(rd);
    cout << "$" << rdDec;
}

void rdrtsa(string reg)
{
    string rd = "";
    string rs = "00000";
    string rt = "";
    string sa = "";
    for (int i = 5; i < 10; i++)
    {
        rt += reg[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 15; i++)
    {
        rd += reg[i];
    }
    int rdDec = BinToDec(rd);
    for (int i = 15; i < 20; i++)
    {
        sa += reg[i];
    }
    int saDec = BinToDec(sa);
    cout << "$" << rdDec;
    cout << ", ";
    cout << "$" << rtDec;
    cout << ", ";
    cout << saDec;
}

void rdrtrs(string reg)
{
    string rd = "";
    string rs = "";
    string rt = "";
    string sa = "00000";
    for (int i = 0; i < 5; i++)
    {
        rs += reg[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 15; i++)
    {
        rd += reg[i];
    }
    int rdDec = BinToDec(rd);
    cout << "$" << rdDec;
    cout << ", ";
    cout << "$" << rtDec;
    cout << ", ";
    cout << "$" << rsDec;
}

// I: rs rt imm
void rtrsimm(string reg3) // 여기부터 수정해보자 !
{
    string rs = "";
    string rt = "";
    string imm = "";
    for (int i = 0; i < 5; i++)
    {
        rs += reg3[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg3[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 26; i++)
    {
        imm += reg3[i];
    }

    if (imm[0] == '0')
    { // 양수는 그대로
        int immDec = BinToDec(imm);
        cout << "$" << rtDec;
        cout << ", ";
        cout << "$" << rsDec;
        cout << ", ";
        cout << immDec;
    }
    else // 음수면 가공
    {
        cout << "$" << rtDec;
        cout << ", ";
        cout << "$" << rsDec;
        cout << ", ";
        BinToImm(imm);
    }
}

void rsrtlab(string reg3)
{
    string rs = "";
    string rt = "";
    string lab = "";
    for (int i = 0; i < 5; i++)
    {
        rs += reg3[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg3[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 26; i++)
    {
        lab += reg3[i];
    }
    if (lab[0] == '0')
    { // 양수는 그대로
        int labDec = BinToDec(lab);
        cout << "$" << rsDec;
        cout << ", ";
        cout << "$" << rtDec;
        cout << ", ";
        cout << labDec;
    }
    else // 음수면 가공
    {
        cout << "$" << rsDec;
        cout << ", ";
        cout << "$" << rtDec;
        cout << ", ";
        BinToImm(lab);
    }
    // int labDec = BinToDec(lab);
    // cout << "$" << rsDec;
    // cout << ", ";
    // cout << "$" << rtDec;
    // cout << ", ";
    // cout << labDec; // *TODO* 음수도 나오나 ??
}

void rtimmrs(string reg3)
{
    string rs = "";
    string rt = "";
    string imm = "";
    for (int i = 0; i < 5; i++)
    {
        rs += reg3[i];
    }
    int rsDec = BinToDec(rs);
    for (int i = 5; i < 10; i++)
    {
        rt += reg3[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 26; i++)
    {
        imm += reg3[i];
    }

    if (imm[0] == '0')
    { // 양수는 그대로
        int immDec = BinToDec(imm);
        cout << "$" << rtDec;
        cout << ", ";
        cout << immDec << "($";
        cout << rsDec << ")";
    }
    else // 음수면 가공
    {
        cout << "$" << rtDec;
        cout << ", ";
        BinToImm(imm);
        cout << "($";
        cout << rsDec << ")";
    }
}

void rtimm(string reg3)
{
    string rt = "";
    string imm = "";
    for (int i = 5; i < 10; i++)
    {
        rt += reg3[i];
    }
    int rtDec = BinToDec(rt);
    for (int i = 10; i < 26; i++)
    {
        imm += reg3[i];
    }
    // int immDec = BinToDec(imm); // 여길 수정해보자 !
    // cout << "$" << rtDec;
    // cout << ", ";
    // cout << immDec;

    if (imm[0] == '0')
    { // 양수는 그대로
        int immDec = BinToDec(imm);
        cout << "$" << rtDec;
        cout << ", ";
        cout << immDec;
    }
    else // 음수면 가공
    {
        cout << "$" << rtDec;
        cout << ", ";
        BinToImm(imm);
    }
}

//stack에 32bits씩 잘라 넣기
void DecToHex(int dec, int count)
{
    string inst = "inst ";
    string s = "";
    string s2 = "00000000";
    string bin = "";
    string op = "";
    string func = "";
    string reg = "";
    string reg2 = "";
    string reg3 = "";
    int rem;
    int dec2;
    if (dec > 0 && dec < 268435456) // 양수이고 맨앞에 0인 경우
    {
        int dec_temp = dec;
        while (dec > 0)
        {
            rem = dec % 16;
            if (rem > 9)
            {
                switch (rem)
                {
                case 10:
                    s = "a" + s;
                    break;
                case 11:
                    s = "b" + s;
                    break;
                case 12:
                    s = "c" + s;
                    break;
                case 13:
                    s = "d" + s;
                    break;
                case 14:
                    s = "e" + s;
                    break;
                case 15:
                    s = "f" + s;
                    break;
                }
            }
            else
            {
                s = char(rem + 48) + s;
            }
            dec = dec / 16;
        }
        if (dec_temp < 16)
            s = "0000000" + s;
        else if (dec_temp >= 16 && dec_temp < 256)
            s = "000000" + s;
        else if (dec_temp >= 256 && dec_temp < 4096)
            s = "00000" + s;
        else if (dec_temp >= 4096 && dec_temp < 65536)
            s = "0000" + s;
        else if (dec_temp >= 65536 && dec_temp < 1048576)
            s = "000" + s;
        else if (dec_temp >= 1048576 && dec_temp < 16777216)
            s = "00" + s;
        else
            s = "0" + s;
        // Little to Big Endian 문자열 변경
        s2[0] = s[6];
        s2[1] = s[7];
        s2[2] = s[4];
        s2[3] = s[5];
        s2[4] = s[2];
        s2[5] = s[3];
        s2[6] = s[0];
        s2[7] = s[1];
        // inst 0: 0000000000 형태 만듬
        // inst = inst + char(count + 48) + ": " + s2;
        cout << inst << count << ": ";
        cout << s2;
        //각 숫자를 binary로
        for (int i = 0; i < 8; i++)
        {
            bin += CharToBin(s2[i]);
        }
        // cout << " " + bin;
        // opcode별 분류
        for (int i = 0; i < 6; i++)
        {
            op += bin[i];
        }
        // reg3 26자리 추출
        for (int i = 6; i < 32; i++)
        {
            reg3 += bin[i];
        }
        if (op == "000000")
        {
            // func 6자리 추출
            for (int i = 26; i < 32; i++)
            {
                func += bin[i];
            }
            // reg 20자리 추출
            for (int i = 6; i < 26; i++)
            {
                reg += bin[i];
            }
            // 뒤에 func 6자리 분류
            if (func == "100000")
            {
                cout << " add ";
                rdrsrt(reg);
            }
            else if (func == "100001")
            {
                cout << " addu ";
                rdrsrt(reg);
            }
            else if (func == "100100")
            {
                cout << " and ";
                rdrsrt(reg);
            }
            else if (func == "011010")
            {
                cout << " div ";
                rsrt(reg);
            }
            else if (func == "011011")
            {
                cout << " divu ";
                rsrt(reg);
            }
            else if (func == "001001")
            {
                cout << " jalr ";
                rdrs(reg);
            }
            else if (func == "001000")
            {
                cout << " jr ";
                rs(reg);
            }
            else if (func == "010000")
            {
                cout << " mfhi ";
                rd(reg);
            }
            else if (func == "010010")
            {
                cout << " mflo ";
                rd(reg);
            }
            else if (func == "010001")
            {
                cout << " mthi ";
                rs(reg);
            }
            else if (func == "010011")
            {
                cout << " mtlo ";
                rs(reg);
            }
            else if (func == "011000")
            {
                cout << " mult ";
                rsrt(reg);
            }
            else if (func == "011001")
            {
                cout << " multu ";
                rsrt(reg);
            }
            else if (func == "100111")
            {
                cout << " nor ";
                rdrsrt(reg);
            }
            else if (func == "100101")
            {
                cout << " or ";
                rdrsrt(reg);
            }
            else if (func == "000000")
            {
                cout << " sll ";
                rdrtsa(reg);
            }
            else if (func == "000100")
            {
                cout << " sllv ";
                rdrtrs(reg);
            }
            else if (func == "101010")
            {
                cout << " slt ";
                rdrsrt(reg);
            }
            else if (func == "101011")
            {
                cout << " sltu ";
                rdrsrt(reg);
            }
            else if (func == "000011")
            {
                cout << " sra ";
                rdrtsa(reg);
            }
            else if (func == "000111")
            {
                cout << " srav ";
                rdrtrs(reg);
            }
            else if (func == "000010")
            {
                cout << " srl ";
                rdrtsa(reg);
            }
            else if (func == "000110")
            {
                cout << " srlv ";
                rdrtrs(reg);
            }
            else if (func == "100010")
            {
                cout << " sub ";
                rdrsrt(reg);
            }
            else if (func == "100011")
            {
                cout << " subu ";
                rdrsrt(reg);
            }
            else if (func == "001100")
            {
                cout << " syscall"; // DONE
            }
            else if (func == "100110")
            {
                cout << " xor ";
                rdrsrt(reg);
            }
            else
            {
                cout << " unknown instruction";
            }
        }
        else if (op == "001000")
        {
            cout << " addi ";
            rtrsimm(reg3);
        }
        else if (op == "001001")
        {
            cout << " addiu ";
            rtrsimm(reg3);
        }
        else if (op == "001100")
        {
            cout << " andi ";
            rtrsimm(reg3);
        }
        else if (op == "000100")
        {
            cout << " beq ";
            rsrtlab(reg3);
        }
        else if (op == "000101")
        {
            cout << " bne ";
            rsrtlab(reg3);
        }
        else if (op == "100000")
        {
            cout << " lb ";
            rtimmrs(reg3);
        }
        else if (op == "100100")
        {
            cout << " lbu ";
            rtimmrs(reg3);
        }
        else if (op == "100001")
        {
            cout << " lh ";
            rtimmrs(reg3);
        }
        else if (op == "100101")
        {
            cout << " lhu ";
            rtimmrs(reg3);
        }
        else if (op == "001111")
        {
            cout << " lui ";
            rtimm(reg3);
        }
        else if (op == "100011")
        {
            cout << " lw ";
            rtimmrs(reg3);
        }
        else if (op == "001101")
        {
            cout << " ori ";
            rtrsimm(reg3);
        }
        else if (op == "101000")
        {
            cout << " sb ";
            rtimmrs(reg3);
        }
        else if (op == "001010")
        {
            cout << " slti ";
            rtrsimm(reg3);
        }
        else if (op == "001011")
        {
            cout << " sltiu ";
            rtrsimm(reg3);
        }
        else if (op == "101001")
        {
            cout << " sh ";
            rtimmrs(reg3);
        }
        else if (op == "101011")
        {
            cout << " sw ";
            rtimmrs(reg3);
        }
        else if (op == "001110")
        {
            cout << " xori ";
            rtrsimm(reg3);
        }
        else if (op == "000010")
        {
            cout << " j ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else if (op == "000011")
        {
            cout << " jal ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else
        {
            cout << " unknown instruction";
        }
    }
    else if (dec > 0 && dec >= 268435456) // 양수이면서 맨 앞자리 0 아닌 경우
    {
        while (dec > 0)
        {
            rem = dec % 16;
            if (rem > 9)
            {
                switch (rem)
                {
                case 10:
                    s = "a" + s;
                    break;
                case 11:
                    s = "b" + s;
                    break;
                case 12:
                    s = "c" + s;
                    break;
                case 13:
                    s = "d" + s;
                    break;
                case 14:
                    s = "e" + s;
                    break;
                case 15:
                    s = "f" + s;
                    break;
                }
            }
            else
            {
                s = char(rem + 48) + s;
            }
            dec = dec / 16;
        }
        // Little to Big Endian 문자열 변경
        s2[0] = s[6];
        s2[1] = s[7];
        s2[2] = s[4];
        s2[3] = s[5];
        s2[4] = s[2];
        s2[5] = s[3];
        s2[6] = s[0];
        s2[7] = s[1];
        // inst 0: 0000000000 형태 만듬
        // inst = inst + char(count + 48) + ": " + s2;
        cout << inst << count << ": ";
        cout << s2;
        //각 숫자를 binary로
        for (int i = 0; i < 8; i++)
        {
            bin += CharToBin(s2[i]);
        }
        // cout << " " + bin;
        // opcode별 분류
        for (int i = 0; i < 6; i++)
        {
            op += bin[i];
        }
        // reg3 26자리 추출
        for (int i = 6; i < 32; i++)
        {
            reg3 += bin[i];
        }
        if (op == "000000")
        {
            // func 6자리 추출
            for (int i = 26; i < 32; i++)
            {
                func += bin[i];
            }
            // reg 20자리 추출
            for (int i = 6; i < 26; i++)
            {
                reg += bin[i];
            }
            // 뒤에 func 6자리 분류
            if (func == "100000")
            {
                cout << " add ";
                rdrsrt(reg);
            }
            else if (func == "100001")
            {
                cout << " addu ";
                rdrsrt(reg);
            }
            else if (func == "100100")
            {
                cout << " and ";
                rdrsrt(reg);
            }
            else if (func == "011010")
            {
                cout << " div ";
                rsrt(reg);
            }
            else if (func == "011011")
            {
                cout << " divu ";
                rsrt(reg);
            }
            else if (func == "001001")
            {
                cout << " jalr ";
                rdrs(reg);
            }
            else if (func == "001000")
            {
                cout << " jr ";
                rs(reg);
            }
            else if (func == "010000")
            {
                cout << " mfhi ";
                rd(reg);
            }
            else if (func == "010010")
            {
                cout << " mflo ";
                rd(reg);
            }
            else if (func == "010001")
            {
                cout << " mthi ";
                rs(reg);
            }
            else if (func == "010011")
            {
                cout << " mtlo ";
                rs(reg);
            }
            else if (func == "011000")
            {
                cout << " mult ";
                rsrt(reg);
            }
            else if (func == "011001")
            {
                cout << " multu ";
                rsrt(reg);
            }
            else if (func == "100111")
            {
                cout << " nor ";
                rdrsrt(reg);
            }
            else if (func == "100101")
            {
                cout << " or ";
                rdrsrt(reg);
            }
            else if (func == "000000")
            {
                cout << " sll ";
                rdrtsa(reg);
            }
            else if (func == "000100")
            {
                cout << " sllv ";
                rdrtrs(reg);
            }
            else if (func == "101010")
            {
                cout << " slt ";
                rdrsrt(reg);
            }
            else if (func == "101011")
            {
                cout << " sltu ";
                rdrsrt(reg);
            }
            else if (func == "000011")
            {
                cout << " sra ";
                rdrtsa(reg);
            }
            else if (func == "000111")
            {
                cout << " srav ";
                rdrtrs(reg);
            }
            else if (func == "000010")
            {
                cout << " srl ";
                rdrtsa(reg);
            }
            else if (func == "000110")
            {
                cout << " srlv ";
                rdrtrs(reg);
            }
            else if (func == "100010")
            {
                cout << " sub ";
                rdrsrt(reg);
            }
            else if (func == "100011")
            {
                cout << " subu ";
                rdrsrt(reg);
            }
            else if (func == "001100")
            {
                cout << " syscall"; // DONE
            }
            else if (func == "100110")
            {
                cout << " xor ";
                rdrsrt(reg);
            }
            else
            {
                cout << " unknown instruction";
            }
        }
        else if (op == "001000")
        {
            cout << " addi ";
            rtrsimm(reg3);
        }
        else if (op == "001001")
        {
            cout << " addiu ";
            rtrsimm(reg3);
        }
        else if (op == "001100")
        {
            cout << " andi ";
            rtrsimm(reg3);
        }
        else if (op == "000100")
        {
            cout << " beq ";
            rsrtlab(reg3);
        }
        else if (op == "000101")
        {
            cout << " bne ";
            rsrtlab(reg3);
        }
        else if (op == "100000")
        {
            cout << " lb ";
            rtimmrs(reg3);
        }
        else if (op == "100100")
        {
            cout << " lbu ";
            rtimmrs(reg3);
        }
        else if (op == "100001")
        {
            cout << " lh ";
            rtimmrs(reg3);
        }
        else if (op == "100101")
        {
            cout << " lhu ";
            rtimmrs(reg3);
        }
        else if (op == "001111")
        {
            cout << " lui ";
            rtimm(reg3);
        }
        else if (op == "100011")
        {
            cout << " lw ";
            rtimmrs(reg3);
        }
        else if (op == "001101")
        {
            cout << " ori ";
            rtrsimm(reg3);
        }
        else if (op == "101000")
        {
            cout << " sb ";
            rtimmrs(reg3);
        }
        else if (op == "001010")
        {
            cout << " slti ";
            rtrsimm(reg3);
        }
        else if (op == "001011")
        {
            cout << " sltiu ";
            rtrsimm(reg3);
        }
        else if (op == "101001")
        {
            cout << " sh ";
            rtimmrs(reg3);
        }
        else if (op == "101011")
        {
            cout << " sw ";
            rtimmrs(reg3);
        }
        else if (op == "001110")
        {
            cout << " xori ";
            rtrsimm(reg3);
        }
        else if (op == "000010")
        {
            cout << " j ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else if (op == "000011")
        {
            cout << " jal ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else
        {
            cout << " unknown instruction";
        }
    }
    else if (dec == 0) // (FINISH) dec이 모두 0인 경우
    {
        s = "00000000";
        //각 숫자를 binary로
        bin = "00000000000000000000000000000000";
        // inst 0: 0000000000 형태 만듬 (끝)
        cout << inst << count << ": ";
        cout << "00000000 sll $0, $0, 0";
    }
    else if (dec < 0) // dec이 음수인 경우
    {
        // 음수를 양수로
        dec2 = dec * (-1);
        int dec_temp2 = dec2;

        // 양수를 hex로
        while (dec2 > 0)
        {
            rem = dec2 % 16;
            if (rem > 9)
            {
                switch (rem)
                {
                case 10:
                    s = "a" + s;
                    break;
                case 11:
                    s = "b" + s;
                    break;
                case 12:
                    s = "c" + s;
                    break;
                case 13:
                    s = "d" + s;
                    break;
                case 14:
                    s = "e" + s;
                    break;
                case 15:
                    s = "f" + s;
                    break;
                }
            }
            else
            {
                s = char(rem + 48) + s;
            }
            dec2 = dec2 / 16;
        }
        if (dec_temp2 < 16)
            s = "0000000" + s;
        else if (dec_temp2 >= 16 && dec_temp2 < 256)
            s = "000000" + s;
        else if (dec_temp2 >= 256 && dec_temp2 < 4096)
            s = "00000" + s;
        else if (dec_temp2 >= 4096 && dec_temp2 < 65536)
            s = "0000" + s;
        else if (dec_temp2 >= 65536 && dec_temp2 < 1048576)
            s = "000" + s;
        else if (dec_temp2 >= 1048576 && dec_temp2 < 16777216)
            s = "00" + s;
        else if (dec_temp2 >= 16777216 && dec_temp2 < 268435456)
            s = "0" + s;
        // 양수의 hex를 binary로
        for (int i = 0; i < 8; i++)
        {
            bin += CharToBin(s[i]);
        }
        // binary 반전 (2의 보수법)
        for (int i = 0; i < 32; i++)
        {
            if (bin[i] == '1')
                bin[i] = '0';
            else if (bin[i] == '0')
                bin[i] = '1';
        }
        // binary 반전 +1 (2의 보수법)
        string TwoComBin;
        TwoComBin = AddBinary(bin, "00000000000000000000000000000001");
        // 이제 음수의 binary를 hex로
        string cmp = "";
        string TwoHex = "";
        int n = 0;
        int m = 0;
        for (n = 0; n < 29; n += 4)
        {
            for (int m = n; m < (n + 4); m++)
            {
                cmp += TwoComBin[m];
            }
            TwoHex += BinToChar(cmp);
            cmp = "";
        }
        // Little to Big Endian 문자열 변경
        s2[0] = TwoHex[6];
        s2[1] = TwoHex[7];
        s2[2] = TwoHex[4];
        s2[3] = TwoHex[5];
        s2[4] = TwoHex[2];
        s2[5] = TwoHex[3];
        s2[6] = TwoHex[0];
        s2[7] = TwoHex[1];
        // inst 0: 0000000000 형태 만듬
        // inst = inst + char(count + 48) + ": " + s2;
        cout << inst << count << ": ";
        cout << s2;
        // 원하는 binary로
        string bin2;
        for (int i = 0; i < 8; i++)
        {
            bin2 += CharToBin(s2[i]);
        }
        // cout << " " + bin2;
        // opcode별 분류
        for (int i = 0; i < 6; i++)
        {
            op += bin2[i];
        }
        // reg3 26자리 추출
        for (int i = 6; i < 32; i++)
        {
            reg3 += bin2[i];
        }
        // cout << " " + reg3;              // DEBUG
        if (op == "000000")
        {
            // func 6자리 추출
            for (int i = 26; i < 32; i++)
            {
                func += bin2[i];
            }
            // reg 20자리 추출
            for (int i = 6; i < 26; i++)
            {
                reg += bin2[i];
            }
            // 뒤에 func 6자리 분류
            if (func == "100000")
            {
                cout << " add ";
                rdrsrt(reg);
            }
            else if (func == "100001")
            {
                cout << " addu ";
                rdrsrt(reg);
            }
            else if (func == "100100")
            {
                cout << " and ";
                rdrsrt(reg);
            }
            else if (func == "011010")
            {
                cout << " div ";
                rsrt(reg);
            }
            else if (func == "011011")
            {
                cout << " divu ";
                rsrt(reg);
            }
            else if (func == "001001")
            {
                cout << " jalr ";
                rdrs(reg);
            }
            else if (func == "001000")
            {
                cout << " jr ";
                rs(reg);
            }
            else if (func == "010000")
            {
                cout << " mfhi ";
                rd(reg);
            }
            else if (func == "010010")
            {
                cout << " mflo ";
                rd(reg);
            }
            else if (func == "010001")
            {
                cout << " mthi ";
                rs(reg);
            }
            else if (func == "010011")
            {
                cout << " mtlo ";
                rs(reg);
            }
            else if (func == "011000")
            {
                cout << " mult ";
                rsrt(reg);
            }
            else if (func == "011001")
            {
                cout << " multu ";
                rsrt(reg);
            }
            else if (func == "100111")
            {
                cout << " nor ";
                rdrsrt(reg);
            }
            else if (func == "100101")
            {
                cout << " or ";
                rdrsrt(reg);
            }
            else if (func == "000000")
            {
                cout << " sll ";
                rdrtsa(reg);
            }
            else if (func == "000100")
            {
                cout << " sllv ";
                rdrtrs(reg);
            }
            else if (func == "101010")
            {
                cout << " slt ";
                rdrsrt(reg);
            }
            else if (func == "101011")
            {
                cout << " sltu ";
                rdrsrt(reg);
            }
            else if (func == "000011")
            {
                cout << " sra ";
                rdrtsa(reg);
            }
            else if (func == "000111")
            {
                cout << " srav ";
                rdrtrs(reg);
            }
            else if (func == "000010")
            {
                cout << " srl ";
                rdrtsa(reg);
            }
            else if (func == "000110")
            {
                cout << " srlv ";
                rdrtrs(reg);
            }
            else if (func == "100010")
            {
                cout << " sub ";
                rdrsrt(reg);
            }
            else if (func == "100011")
            {
                cout << " subu ";
                rdrsrt(reg);
            }
            else if (func == "001100")
            {
                cout << " syscall"; // DONE
            }
            else if (func == "100110")
            {
                cout << " xor ";
                rdrsrt(reg);
            }
            else
            {
                cout << " unknown instruction";
            }
        }
        else if (op == "001000")
        {
            cout << " addi ";
            rtrsimm(reg3);
        }
        else if (op == "001001")
        {
            cout << " addiu ";
            rtrsimm(reg3);
        }
        else if (op == "001100")
        {
            cout << " andi ";
            rtrsimm(reg3);
        }
        else if (op == "000100")
        {
            cout << " beq ";
            rsrtlab(reg3);
        }
        else if (op == "000101")
        {
            cout << " bne ";
            rsrtlab(reg3);
        }
        else if (op == "100000")
        {
            cout << " lb ";
            rtimmrs(reg3);
        }
        else if (op == "100100")
        {
            cout << " lbu ";
            rtimmrs(reg3);
        }
        else if (op == "100001")
        {
            cout << " lh ";
            rtimmrs(reg3);
        }
        else if (op == "100101")
        {
            cout << " lhu ";
            rtimmrs(reg3);
        }
        else if (op == "001111")
        {
            cout << " lui ";
            rtimm(reg3);
        }
        else if (op == "100011")
        {
            cout << " lw ";
            rtimmrs(reg3);
        }
        else if (op == "001101")
        {
            cout << " ori ";
            rtrsimm(reg3);
        }
        else if (op == "101000")
        {
            cout << " sb ";
            rtimmrs(reg3);
        }
        else if (op == "001010")
        {
            cout << " slti ";
            rtrsimm(reg3);
        }
        else if (op == "001011")
        {
            cout << " sltiu ";
            rtrsimm(reg3);
        }
        else if (op == "101001")
        {
            cout << " sh ";
            rtimmrs(reg3);
        }
        else if (op == "101011")
        {
            cout << " sw ";
            rtimmrs(reg3);
        }
        else if (op == "001110")
        {
            cout << " xori ";
            rtrsimm(reg3);
        }
        else if (op == "000010")
        {
            cout << " j ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else if (op == "000011")
        {
            cout << " jal ";
            for (int i = 6; i < 32; i++)
            {
                reg2 += bin[i];
            }
            int reg2Dec = BinToDec(reg2);
            cout << reg2Dec;
        }
        else
        {
            cout << " unknown instruction";
        }
    }
}

int main(int argc, char *argv[])
{
    // ifstream fi;

    // char fname[200];
    char *fname = argv[1];
    ifstream fi;
    // scanf("%s", fname);

    fi.open(fname, ostream::binary); // 읽기용 이진 파일 열기
    if (!fi)
    {
        cerr << "읽기용 파일 오픈에 실패했습니다!" << endl;
        exit(1);
    }

    // 이진 데이터를 읽어와서 숫자로 출력
    int n;
    int count = 0; // 명령어 개수 세기

    while (!fi.eof())
    {
        fi.read((char *)&n, sizeof(int));
        // cout << n << '\n';
        // cout << "inst " + count;
        // cout << ": ";
        if (fi.eof())
            break;
        DecToHex(n, count);
        cout << '\n';
        count++;
    }
    fi.close(); // 읽기용 파일 닫기

    return 0;
}