#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

//��ͼƬ����
void InitGame()
{
    loadimage(&imgbk, "fm.jpg", 560, 600);
	loadimage(&imgmes1, "mes1.jpg", 560, 600);
	loadimage(&imgmes2, "mes2.jpg", 560, 600);
    loadimage(&img01, "1.jpg", 560, 55);
    loadimage(&img02, "2.jpg", 560, 55);
    loadimage(&img03, "3.jpg", 560, 55);
    loadimage(&img04, "4.jpg", 560, 55);
    loadimage(&img05, "5.jpg", 560, 55);
    loadimage(&img06, "6.jpg", 560, 55);
    loadimage(&img0, "blank.jpg", 40, 40);//�յ�
    loadimage(&img1, "wall.jpg", 40, 40);//ǽ
    loadimage(&img2, "box1.jpg", 40, 40);//����
    loadimage(&img3, "r.jpg", 40, 40);//��
    loadimage(&img4, "ok.jpg", 40, 40);//Ŀ�ĵ�
    loadimage(&img5, "box2.jpg", 40, 40);//���ӵ���Ŀ�ĵ�
    loadimage(&img15, "15.jpg", 40, 40);//��ɫǽ1
    loadimage(&img16, "16.jpg", 40, 40);//��ɫǽ2
    loadimage(&img20, "20.jpg", 40, 40);//��ɫǽ
    loadimage(&img21, "21.jpg", 40, 40);//��ɫǽ
    loadimage(&img22, "22.jpg", 40, 40);//ǳ��ɫǽ
    loadimage(&img23, "23.jpg", 40, 40);//����ɫǽ
    loadimage(&img24, "24.jpg", 40, 40);//��ɫǽ
    loadimage(&img40, "40.jpg", 40, 40);//��
    loadimage(&img50, "50.jpg", 40, 40);//��
}

//�˵�����
char menu()
{
    char n;
    putimage(0, 0, &imgbk);
    n=_getch();
    return n;
}