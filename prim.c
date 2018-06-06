
#include<stdio.h>
#include<conio.h>
#define size 100 //�ִ� ���� �ĺ��� �� ����
#define MAX 1000 //�ִ� ���� �Ǽ� ��� ����

int print[MAX][MAX] = { 0 };
int u, w=0;
//����� ���� ���� �� �迭

void prim(int road[][size], int n, int T)
{
	int i, j, k = 2; //�ݺ����� ���� ����
	int min, s, e, hap = 0;
	int spot[size]; //���İ� ���ø� üũ�ϱ� ���� �迭
					//min = �ּ� ���, hap = �ּ� ������� �Ǽ��� ������ ��� ��
					// s�� e�� ���� �ĺ��� �մ� �� ������ ��ȣ

	u = 0;
	for (i = 1; i <= n; i++)
		spot[i] = 0;
	//�迭 �ʱ�ȭ
	spot[1] = 1; //���� ���� üũ
	do {
			min = MAX;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (road[i][j] != 0)
				{
					if ((spot[i] && !spot[j]) || (!spot[i] && spot[j]))
					{
						if (road[i][j] < min)
						{

							min = road[i][j];
							s = i;
							e = j;
						}
					}
				}
			}
		} //üũ�� ���ø� Ȯ���ϰ�, ���� �ּұݾ����� �� �� �ִ� ���θ� ã�� �ݺ���.

		print[T][u] = s;
		u++;
		print[T][u] = e;
		u++;
		print[T][u] = min;
		u++;
		//���������� ������ ������ �迭�� ����
		spot[s] = spot[e] = 1; //������ ������ ���� üũ
		hap = hap + min; //������ ������ �Ǽ� ����� ����
		
		k++;
	} while (k <= n); // ������ �� ��ŭ(�ִܰŸ�) �ݺ�

	printf("\n\n%d\n\n", (spot[n] && !spot[3]) || (!spot[n] && spot[3]));
	print[T][u] = hap; //���� ����
	w += u; //����� Ƚ���� ����
}
void main()
{
	int road[size][size], n;
	int s, e, c, i, j, m;
	//n�� ������ ��, m�� �ĺ� ������ ��
	// s�� e�� ���� �ĺ��� �մ� �� ������ ��ȣ�̰�, c�� �� ���θ� �Ǽ��ϴµ� ��� ���
	// road[][]�� ����
	int T, k; //T�� ���̽� �ݺ�
	//���̽� �ݺ� �� �� ���̽��� ����� ���� ����
	scanf_s("%d", &T);


	while (T > 10)
	{
		printf("CASE ������ �ʰ��߽��ϴ�. �ٽ� �Է����ּ���.\n");
		scanf_s("%d", &T);
	}
	for (k = 0; k < T; k++)
	{
		scanf_s("%d", &n); //������ �� �Է�
		while (n <2 || n>20)
		{
			if(n>20)
				printf("������ ���� �ʰ��Ͽ����ϴ�. �ٽ� �Է����ּ���.\n");
			else
				printf("������ ���� 2���� ���� �� �����ϴ�. �ٽ� �Է����ּ���.\n");
			scanf_s("%d", &n);
		}
		scanf_s("%d", &m); // ���� �ĺ��� �� �Է�
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				road[i][j] = 0; //�迭 �ʱ�ȭ


		for (i = 1; i <= m; i++)
		{
			scanf_s("%d %d %d", &s, &e, &c);
			road[s][e] = road[e][s] = c;
		} // m���� �� ���� �ĺ��� ������ �Է�

		prim(road, n, k); //����� �迭�� �̿��Ͽ� Prim �˰��� ����
			
	}
	printf("\n");
	for (i = 0; i < T; i++)
	{
		for (j = 0; j <= w; j++)
		{
			if (print[i][j])
			{
				if (j && j % 3 == 0)
				{
					printf("\n");
				}
				printf("%d ", print[i][j]);

			}
		
			//������ ���� �ݺ��� ���� ���� �ݺ��� break;
		}
		printf("\n\n");
	}

	//����� ���� ����� �迭 ������ ���
	getchar();
	getchar();
}

