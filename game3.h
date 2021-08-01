#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map02[9][8];

//���������Ա㴫ֵ
void Create3(int map3[9][8])
{
    int i, j;
    for (i = 0;i < 9;i++)
    {
        for (j = 0;j < 8;j++)
        {
            map3[i][j] = map02[i][j];
        }
    }
}

//���Ƶ����ؽ��漰��ͼ
void DrawMap3(int map3[9][8])
{
    BeginBatchDraw();
    putimage(0, 0, &img03);
    //��forѭ����������
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            switch (map3[i][j])
            {
            case 0:
                putimage((j + 3) * 40, (i + 2) * 40, &img0);
                break;
				
            case 20:
				//��ɫǽ20
                putimage((j + 3) * 40, (i + 2) * 40, &img20);
                break;
            case 21:
				//��ɫǽ21
                putimage((j + 3) * 40, (i + 2) * 40, &img21);
                break;
            case 22:
				//ǳ��ǽ22
                putimage((j + 3) * 40, (i + 2) * 40, &img22);
                break;
            case 23:
				//��ɫǽ23
                putimage((j + 3) * 40, (i + 2) * 40, &img23);
                break;
            case 24:
				//��ɫ24
                putimage((j + 3) * 40, (i + 2) * 40, &img24);
                break;
            case 50:
				//�հ�ǽ50
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
                break;
            case 3:                
                putimage((j + 3) * 40, (i + 2) * 40, &img4);
                break;
            case 4:               
                putimage((j + 3) * 40, (i + 2) * 40, &img2);
                break;
            case 5:
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            case 7:
				//���ӵ���Ŀ�ĵ� 4+3=7
                putimage((j + 3) * 40, (i + 2) * 40, &img5);
                break;
            case 8:
				//�˵���Ŀ�ĵ� 5+3=8
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "����");
    outtextxy(30, 420, "һ��һ��������");
    putimage(0, 545, &img06);
    EndBatchDraw();
}

int PlayGame3(int map3[9][8])
{
    //��ȡ����ǰ���˵��±�
    int row, col;//�˵� �� �� ��
    char x;//�˳�ʱy/n
    for (int i = 0;i < 9;i++)//���Ʊ��� 0-6
    {
        for (int j = 0;j < 8;j++)//���Ʊ���0-9
        {
            if (map3[i][j] == 5)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

	//�ж�ʤ��
    if ((map3[6][1] == 7 || map3[6][2] == 7 || map3[6][3] == 7 || map3[6][4] == 7 || map3[6][5] == 7 || map3[6][6] == 7) && (map3[7][6] == 7))
    {
        settextstyle(30, 0, "����");
        outtextxy(30, 450, "��ϲ��!�ɹ�ͨ���˵�����!");
        return 1;
    }

    //����������ͼ������Ӧ����
    char input;//����һ���ַ�����
    input = _getch();//���ܼ�����������Ӧ��ֵ
    //getch() ����ʾ���ģ����¼������Ͻ���*/
    switch (input)
    {
        /************************************
        ����������Щ���
        1.�˵�ǰ���ǿյ�
        2.�˵�ǰ����Ŀ�ĵ�:�ƶ�Ŀ�ĵ�
        3.�˵�ǰ�������������ӵ�ǰ���ǿյ�
        4.�˵�ǰ�������������ӵ�ǰ����Ŀ�ĵ�
        5.�˵�ǰ����Ŀ�ĵ���Ŀ�ĵ�ǰ���ǿյ�
        6.�˵�ǰ����Ŀ�ĵ���Ŀ�ĵ�ǰ����ǽ
        7.�˵�ǰ����Ŀ�ĵ���Ŀ�ĵ�ǰ��������
        *************************************/
        //ǽΪ1 �յ�Ϊ0 ��Ϊ5 ����Ϊ4 Ŀ�ĵ�Ϊ3  ���ӵ���Ŀ�ĵ�7
    case 'w'://��
        if (map3[row - 1][col] == 0)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map3[row][col] -= 5;//�˵�ID 5/8
            map3[row - 1][col] += 5;
        }
        else if (map3[row - 1][col] == 4 || map3[row - 1][col] == 7)//�˵�ǰ��������
        {
            if (map3[row - 2][col] == 0 || map3[row - 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map3[row - 2][col] += 4;
                map3[row - 1][col] += 1;
                map3[row][col] -= 5;
            }
        }
        else if (map3[row - 1][col] == 3 && map3[row - 2][col] == 0)//����˵�ǰ����Ŀ�ĵ�
        {
            map3[row][col] = 0;
            map3[row - 1][col] = 5;
            map3[row - 2][col] = 3;
        }

        break;
    case 'a'://��
        if (map3[row][col - 1] == 0)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map3[row][col] -= 5;//�˵�ID 5/8
            map3[row][col - 1] += 5;
        }
        else if (map3[row][col - 1] == 4 || map3[row][col - 1] == 7)//�˵�ǰ��������
        {
            if (map3[row][col - 2] == 0 || map3[row][col - 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map3[row][col - 2] += 4;
                map3[row][col - 1] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row][col - 1] == 3 && map3[row][col - 2] == 0)//����˵�ǰ����Ŀ�ĵ�
        {
            map3[row][col] = 0;
            map3[row][col - 1] = 5;
            map3[row][col - 2] = 3;
        }
		else if (map3[row][col - 1] == 3 && map3[row][col - 2] == 4)
		{
			map3[row][col] = 0;
			map3[row][col - 1] = 5;
			map3[row][col - 2] += 3;
		}
		break;
    case 's'://��
        if (map3[row + 1][col] == 0)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map3[row][col] -= 5;//�˵�ID 5/8
            map3[row + 1][col] += 5;
        }
        else if (map3[row + 1][col] == 4 || map3[row + 1][col] == 7)//�˵�ǰ��������
        {
            if (map3[row + 2][col] == 0 || map3[row + 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map3[row + 2][col] += 4;
                map3[row + 1][col] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row + 1][col] == 3 && map3[row + 2][col] == 0)//����˵�ǰ����Ŀ�ĵ�
        {
            map3[row][col] = 0;
            map3[row + 1][col] = 5;
            map3[row + 2][col] = 3;
        }
		else if (map3[row + 1][col] == 3 && map3[row+2][col] == 4)
		{
			map3[row][col] = 0;
			map3[row + 1][col] = 5;
			map3[row + 2][col] += 3;
		}
        break;
    case 'd'://��
        if (map3[row][col + 1] == 0)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map3[row][col] -= 5;//�˵�ID 5/8
            map3[row][col + 1] += 5;
        }
        else if (map3[row][col + 1] == 4 || map3[row][col + 1] == 7)//�˵�ǰ��������
        {
            if (map3[row][col + 2] == 0 || map3[row][col + 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map3[row][col + 2] += 4;
                map3[row][col + 1] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row][col + 1] == 3 && map3[row][col + 2] == 0)//����˵�ǰ����Ŀ�ĵ�
        {
            map3[row][col] = 0;
            map3[row][col + 1] = 5;
            map3[row][col + 2] = 3;
        }
		else if (map3[row][col + 1] == 3 && map3[row][col + 2] == 4)
		{
			map3[row][col] = 0;
			map3[row][col + 1] = 5;
			map3[row][col + 2] += 3;
		}
		
        break;
    case 'q'://�˳�
        settextstyle(25, 0, "����");
        outtextxy(30, 450, "������ȷ��Ҫ�˳��Ѷ�Ϊ�����򵥵ĵ�������?");
        settextstyle(25, 0, "����");
        outtextxy(30, 485, "��ѡ��:(y/n)");
        x = _getch();
        if (x == 'y')
            return 1;
        break;
    case 'r'://���¿�ʼ����
        return 3;
        break;
    }
    return 0;
}