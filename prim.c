
#include<stdio.h>
#include<conio.h>
#define size 100 //최대 도로 후보의 수 지정
#define MAX 1000 //최대 도로 건설 비용 지정

int print[MAX][MAX] = { 0 };
int u, w=0;
//출력을 위한 변수 및 배열

void prim(int road[][size], int n, int T)
{
	int i, j, k = 2; //반복문을 위한 변수
	int min, s, e, hap = 0;
	int spot[size]; //거쳐간 도시를 체크하기 위한 배열
					//min = 최소 비용, hap = 최소 비용으로 건설된 도로의 비용 합
					// s와 e는 도로 후보가 잇는 각 도시의 번호

	u = 0;
	for (i = 1; i <= n; i++)
		spot[i] = 0;
	//배열 초기화
	spot[1] = 1; //시작 도시 체크
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
		} //체크된 도시를 확인하고, 가장 최소금액으로 갈 수 있는 도로를 찾는 반복분.

		print[T][u] = s;
		u++;
		print[T][u] = e;
		u++;
		print[T][u] = min;
		u++;
		//최종적으로 구해진 값들을 배열에 저장
		spot[s] = spot[e] = 1; //지나간 도시의 값을 체크
		hap = hap + min; //정해진 도로의 건설 비용을 더함
		
		k++;
	} while (k <= n); // 도시의 수 만큼(최단거리) 반복
	print[T][u] = hap; //합을 저장
	w += u; //저장된 횟수를 저장
}
void main()
{
	int road[size][size], n;
	int s, e, c, i, j, m;
	//n은 도시의 수, m은 후보 도로의 수
	// s와 e는 도로 후보가 잇는 각 도시의 번호이고, c는 그 도로를 건설하는데 드는 비용
	// road[][]는 도로
	int T, k; //T는 케이스 반복
	//케이스 반복 후 각 케이스별 출력을 위한 변수
	scanf_s("%d", &T);


	while (T > 10)
	{
		printf("CASE 범위를 초과했습니다. 다시 입력해주세요.\n");
		scanf_s("%d", &T);
	}
	for (k = 0; k < T; k++)
	{
		scanf_s("%d", &n); //도시의 수 입력
		while (n <2 || n>20)
		{
			if(n>20)
				printf("도시의 수를 초과하였습니다. 다시 입력해주세요.\n");
			else
				printf("도시의 수는 2보다 작을 수 없습니다. 다시 입력해주세요.\n");
			scanf_s("%d", &n);
		}
		scanf_s("%d", &m); // 도로 후보의 수 입력
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				road[i][j] = 0; //배열 초기화


		for (i = 1; i <= m; i++)
		{
			scanf_s("%d %d %d", &s, &e, &c);
			road[s][e] = road[e][s] = c;
		} // m개의 각 도로 후보의 정보를 입력

		prim(road, n, k); //저장된 배열을 이용하여 Prim 알고리즘 실행
			
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
		
			//없으면 다음 반복을 위해 열의 반복을 break;
		}
		printf("\n\n");
	}

	//출력을 위해 저장된 배열 값들을 출력
	getchar();
	getchar();
}

