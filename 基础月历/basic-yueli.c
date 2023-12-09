#include<stdio.h>
//#define month_s 13
//判断闰平年
int yearof_rp(int n){
    int a=(n%4==0&&n%100!=0)||(n%400==0);
    return a?1:0;
}

// 判断该年第一天为星期几(注意：公元1年第一天为星期1)
int yearfirstday(int n){
    int sum_day=1,y_firstday;
    for(int i=1;i<n;i++){
        if(yearof_rp(n)==1){
            sum_day=sum_day+366;
        }
        else{
            sum_day=sum_day+365;
        }
        }
    y_firstday=sum_day%7;
    return y_firstday;
}
// 0为周日
    
//判断每个月第一天星期几
int monthfirstday(int n,int m)/* n为年 m为月*/{
    int m_firstday,sum_day_m=yearfirstday(n);
    int months[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if (yearof_rp(n)==0){
        months[2]=28;
        }    
    for(int i=1;i<m;i++){
        sum_day_m=sum_day_m+months[i];//
    }
    m_firstday=sum_day_m%7;
    return m_firstday;
}

void printSquare(int Square[][7],int n,int m){
    int months[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if (yearof_rp(n)==1){
        months[2]=29;
    }
    else {
        months[2]=28;
        }    
    int row=0;
    int col=monthfirstday(n,m);
    for(int blank=0;blank<col;blank++){
        printf("   ");
    }
    for (int num = 1; num <= months[m]; num++) {
        Square[row][col] = num;
        printf("%3d", Square[row][col]);
        
        if (col > 6) {
            row++;
            col = 0;
        }
        if (col == 6) {
            printf("\n");
        }
        col++;
    }
}

int map(void){
    const char *week[] = {
    "日","一", "二", "三", "四",
    "五", "六"
    };
    for(int i=0;i<7;i++){
        int month=12;
        if(i==3){
            printf("%3d月",month);
        }
        else {
            printf("___");
        }
    }
    printf("\n");
    for(int i=0;i<7;i++){
        printf("%4s",week[i]);
    }
    printf("\n");
}

int yearof_rp(int n);
int yearfirstday(int n);
int monthfirstday(int n,int m);
void printSquare(int Square[][7],int n,int m);
int map(void);

int main(void){
    int n,m;
    printf("请输入年份：\n");
    scanf("%d",&n);
    printf("请输入月份:\n");
    scanf("%d",&m);
    map();
    int Square[7][7];
    printSquare(Square,n,m);
}