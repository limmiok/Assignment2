#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat copy1, copy2;
struct tm *time_1, *time_2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
	stat("test1", &copy1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
	stat("test2", &copy2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	time_1 = localtime(&copy1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	time_2 = localtime(&copy2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	int size1 = copy1.st_size;
	int size2 = copy2.st_size;

	printf("size compare\n");

	if (size1 > size2)
		printf("test1 is bigger\n");
	else if (size2 > size1)
		printf("test2 is bigger\n");
	else
		printf("sizes are equal\n");
	printf("\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	int block1 = copy1.st_blocks;
	int block2 = copy2.st_blocks;

	printf("block compare\n");

	if (block1 > block2)
		printf("test1 is bigger\n");
	else if (block2 > block1)
		printf("test2 is bigger\n");
	else
		printf("sizes are equal\n");
	printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	int month1 = time_1->tm_mon + 1;
	int month2 = time_2->tm_mon + 1;
	int date1 = time_1->tm_mday;
	int date2 = time_2->tm_mday;

	printf("date compare\n");
	if (month1 < month2)
		printf("test1 is early\n");
	else if (month2 < month1)
		printf("test2 is early\n");
	else
	{
		if (date1 < date2)
			printf("test1 is early\n");
		else if (date2 < date1)
			printf("test2 is early\n");
		else
			printf("same date\n");
	}
	printf("\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	int hour1 = time_1->tm_hour;
	int hour2 = time_2->tm_hour;
	int min1 = time_1->tm_min;
	int min2 = time_2->tm_min;

	printf("time compare\n");

	if (hour1 < hour2)
		printf("test1 is early\n");
	else if (hour2 < hour1)
		printf("test2 is early\n");
	else
	{
		if (min1 < min2)
			printf("test1 is early\n");
		else if (min2 < min1)
			printf("test2 is early\n");
		else
			printf("same time\n");
	}
	printf("\n");
}
