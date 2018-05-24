#include <stdio.h>
#include <string.h>
#include <math.h>

double a[1005];

int main(){
    int n;
    scanf("%d",&n);
    double m_min = -1,m_max = -1;
    int m_min_p = -1,m_max_p = -1;

    double sum = 0;
    for(int i = 0;i < n;i++){
        scanf("%lf",&a[i]);
        if(m_min_p == -1 || a[i] < m_min){
            m_min = a[i];
            m_min_p = i;
        }
        if(m_max_p == -1  || a[i] > m_max){
            m_max = a[i];
            m_max_p = i;
        }
        sum += a[i];
    }

    sum -= m_min;
    sum -= m_max;
    //printf("min = %.1lf  ,max = %.1lf\n",m_min,m_max);
    double avg = sum / (double)(n-2);
    double max_err = 0;
    for(int i = 0;i < n;i++){
        if(i == m_min_p || i == m_max_p){
            continue;
        }
        double tmp = fabs(avg-a[i]);
        if(tmp > max_err){
            max_err = tmp;
        }
    }

    printf("%.2lf %.2lf\n",avg,max_err);
    return 0;
}

