#include"DxLib.h"
#include"ranking.h"

Ranking ranking;

/***********************************************
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
int  Ranking::SaveRanking(void){

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/chapter4/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}
	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}
	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

/*************************************
 * �����L���O�f�[�^�ǂݍ���
 *************************************/
int Ranking::ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name,11, &g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}
/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void Ranking::SortRanking(void)
{
	int i, j;
	RankingData work;
	// �I��@�\�[�g
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}
	// ���ʕt��
	for (i = 0; i < 10; i++) {
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}
RankingData Ranking::getRankingData(int i) {
	return g_Ranking[i];
}