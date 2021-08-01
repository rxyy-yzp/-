#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map00[7][10];

//���������Ա㴫ֵ
void Create1(int map1[7][10])
{
    int i, j;
    for (i = 0;i < 7;i++)
    {
        for (j = 0;j < 10;j++)
        {
            map1[i][j] = map00[i][j];
        }
    }
}

//���Ƶ�һ�ؽ��漰��ͼ
void DrawMap1(int map1[7][10])
{   
    /*��forѭ����������*/
    BeginBatchDraw();
    putimage(0, 0, &img01);   

    for (int i = 0;i < 7;i++)
    {
        for (int j = 0;j < 10;j++)
        {
            switch (map1[i][j])
            {
            case 0:
                putimage((j + 2) * 40, (i + 2) * 40, &img0);
                break;
            case 1:
                putimage((j + 2) * 40, (i + 2) * 40, &img1);
                break;
            case 3:
                putimage((j + 2) * 40, (i + 2) * 40, &img4);
                break;
            case 4:
                putimage((j + 2) * 40, (i + 2) * 40, &img2);
                break;
            case 5:
                putimage((j + 2) * 40, (i + 2) * 40, &img3);
                break;
            case 7:
				//���ӵ���Ŀ�ĵ� 4+3=7
                putimage((j + 2) * 40, (i + 2) * 40, &img5);
                break;
            case 8:
				//�˵���Ŀ�ĵ� 5+3=8
                putimage((j + 2) * 40, (i + 2) * 40, &img3);
                break;
            case 50:
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
                break;
            case 10:
				//�ʵ�
                putimage((j + 2) * 40, (i + 2) * 40, &img1);
                break;
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "����");
    outtextxy(30, 360, "�������������ƶ���!"); 
    putimage(0, 545, &img04);
    EndBatchDraw();
}

//������Ϸ
int PlayGame1(int map1[7][10])
{
    //��ȡ����ǰ���˵��±�
    int row, col;//�˵� �� �� ��
    char x;//�˳�ʱy/n
    for (int i = 0;i < 7;i++)//���Ʊ��� 0-6
    {
        for (int j = 0;j < 10;j++)//���Ʊ���0-9
        {
            if (map1[i][j] == 5 || map1[i][j] == 8)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

	//�ж�ʤ��
    if (map1[2][2] == 7 && map1[3][1] == 7 && map1[3][2] == 7 && map1[4][1] == 7 && map1[4][2] == 7)
    {
        settextstyle(30, 0, "����");
        outtextxy(30, 405, "��ϲ��!�ɹ�ͨ���˵�һ��!");
        return 2;
    }

    //����������ͼ������Ӧ������
    char input;//����һ���ַ�����
    input = _getch();/*���ܼ�����������Ӧ��ֵ*/
    //getch() ����ʾ���ģ����¼������Ͻ���
    switch (input)
    {
        /************************************
        ����������Щ���
        1.�˵�ǰ���ǿյ�
        2.�˵�ǰ����Ŀ�ĵ�
        3.�˵�ǰ�������������ӵ�ǰ���ǿյ�
        4.�˵�ǰ�������������ӵ�ǰ����Ŀ�ĵ�
        *************************************/
    case 'w'://��
        if (map1[row - 1][col] == 0 || map1[row - 1][col] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map1[row][col] -= 5;//�˵�ID 5/8
            map1[row - 1][col] += 5;
        }
        else if (map1[row - 1][col] == 4 || map1[row - 1][col] == 7)//�˵�ǰ��������
        {
            if (map1[row - 2][col] == 0 || map1[row - 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map1[row - 2][col] += 4;
                map1[row - 1][col] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 'a'://��
        if (map1[row][col - 1] == 0 || map1[row][col - 1] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map1[row][col] -= 5;//�˵�ID 5/8
            map1[row][col - 1] += 5;
        }
        else if (map1[row][col - 1] == 4 || map1[row][col - 1] == 7)//�˵�ǰ��������
        {
            if (map1[row][col - 2] == 0 || map1[row][col - 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map1[row][col - 2] += 4;
                map1[row][col - 1] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 's'://��
        if (map1[row + 1][col] == 0 || map1[row + 1][col] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map1[row][col] -= 5;//�˵�ID 5/8
            map1[row + 1][col] += 5;
        }
        else if (map1[row + 1][col] == 4 || map1[row + 1][col] == 7)//�˵�ǰ��������
        {
            if (map1[row + 2][col] == 0 || map1[row + 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map1[row + 2][col] += 4;
                map1[row + 1][col] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 'd'://��
        if (map1[row][col + 1] == 0 || map1[row][col + 1] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map1[row][col] -= 5;//�˵�ID 5/8
            map1[row][col + 1] += 5;
        }
        else if (map1[row][col + 1] == 4 || map1[row][col + 1] == 7)//�˵�ǰ��������
        {
            if (map1[row][col + 2] == 0 || map1[row][col + 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map1[row][col + 2] += 4;
                map1[row][col + 1] += 1;
                map1[row][col] -= 5;
            }

        }
        else if (map1[row][col + 1] == 10)//������Ϊ�ʵ��񣬿����Ƴ�ǽ��
        {
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "����");
            outtextxy(30, 390, "��ǽ�ڸ���?�����ӳ�ȥ��?"); 
            outtextxy(30, 420, "�����������...");
            system("pause");
            outtextxy(30, 450, "�����Ϸ��������!");
            outtextxy(30, 480, "��ϲ��!��һ��ʧ����!");
            return 1;
        }
        break;
    case 'q'://�˳�
        settextstyle(25, 0, "����");
        outtextxy(30, 420, "������ȷ��Ҫ�˳��Ѷ�Ϊ�򵥵ĵ�һ����?");
        settextstyle(25, 0, "����");
        outtextxy(30, 455, "��ѡ��:(y/n)");
        x=_getch();
        if (x == 'y')
            return 1;
        break;
    case 'r'://���¿�ʼ����
        return 3;
        break;
    }
    return 0;
}