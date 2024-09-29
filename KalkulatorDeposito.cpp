#include <stdio.h>

int getDeposito(){
double deposito;
printf("Note: Nilai deposito USD $ 100 - USD $ 10.000\n");
do{
    printf("Masukkan jumlah yang ingin dideposito ($): ");
    scanf("%lf",&deposito);
} while (deposito<100 || deposito>10000);
return deposito;
}

int getTenor(){
int tenor;
double bunga;
printf("\nPilihan\t Tenor\t Bunga/tahun (%%):\n");
printf("1.\t 1 bulan\t 3.4%\n");
printf("2.\t 3 bulan\t 3.6%\n");
printf("3.\t 6 bulan\t 3.75%\n");
printf("4.\t 12 bulan\t 4.2%\n\n");
do {
    printf("Masukkan Tenor yang dipilih: ");
    scanf("%d",&tenor);
    if (tenor==1) printf("Tenor yang dipilih 1 bulan dengan bunga/tahun 3.4%%\n\n");
    else if (tenor==2) printf("Tenor yang dipilih 3 bulan dengan bunga/tahun 3.6%%\n\n");
    else if (tenor==3) printf("Tenor yang dipilih 6 bulan dengan bunga/tahun 3.75%%\n\n");
    else if (tenor==4) printf("Tenor yang dipilih 12 bulan dengan bunga/tahun 4.2%%\n\n");
    else printf("Pilihan tenor tidak tersedia\n");
} while (tenor>4 || tenor<1);
return tenor;
}


int getYear(){
int year;
printf("Note: Durasi deposito 1thn - 10thn\n");
do{
    printf("Masukkan berapa tahun rencana Anda akan mendepositokannya: ");
    scanf("%d",&year);
} while (year<1 || year>10);
return year;
}

int getinput(double *deposito1,int *tenor1,int *year1){
*deposito1=getDeposito();
*tenor1=getTenor();
*year1=getYear();
return *deposito1, *tenor1, *year1;
}

double netinvesment(double depositoawal, double bungakotor,double deduction){

    double bunganet=0;
    double netinvest=0;
    bunganet=bungakotor-deduction;
    netinvest=depositoawal+bunganet;

    printf("\nTotal Pendapatan bunga (net): %.2lf\n", bunganet);
    printf("\nTotal Investasi: %.2lf\n\n\n", netinvest);
    return 0;
}

double deduction(double bungaa, double ppha){
 double expense;
 double incometaxs;
 double totaldeduct;

 expense = bungaa/100;
 incometaxs=ppha*bungaa;
 totaldeduct=expense+incometaxs;
 printf("\nDeduction: \nInterest Expense %.2lf\nIncomeTax %.2lf",expense,incometaxs);

return totaldeduct;
}
double calculate (double deposito3, int tenor3, int year3){
int i;
int t;
int x;
int n;
int tenor;
double saving1;
double bunga;
double bunga1;

saving1=deposito3;
tenor=tenor3;

if (tenor==1) {
bunga=0.034/12;
t=1; 
n=12/t;
}
if (tenor==2) {
bunga=0.036/12;
t=3;
n=12/t;
}  

if (tenor==3) {
bunga=0.0375/12;
t=6;
n=12/t;
}

if (tenor==4){
bunga=0.042/12;
t=12;
n=12/t;
} 
x=n*year3;

//Crosscheck nilai

printf("\nSUMMARY: Deposito: %0.lf Tenor: %d Year: %d Bunga: %lf Repetition: %d\n",deposito3,t,year3,bunga,x);
printf("\nPeriode\t Bunga\t Saldo\n");
for (i=0; i<=x; i++){
bunga1=deposito3-saving1;
printf("%d\t %.2lf\t %.2lf\n",i,bunga1,deposito3);
deposito3=deposito3+(deposito3*bunga*t);
// deposito3 += deposito * bunga * t;
}
return bunga1;
}

int main () {
double deposito4;
double bunga;
double bunganet;
double totaldeduction;
int tenor2;
int year2;
double pph;
double a;

printf("\t\t==Program Kalkulator Deposito Bank XYZ==\n\n");
deposito4,tenor2,year2= getinput(&deposito4,&tenor2,&year2);
if (deposito4<1000){
     (pph=0);
}else if (deposito4>=1000){
    (pph=0.2);
} 
bunga=calculate(deposito4,tenor2,year2);
printf("Total Pendapatan Bunga (gross): %.2lf\n",bunga);

totaldeduction=deduction(bunga,pph); 
printf("\nTotal deduction: %.2lf\n",totaldeduction);

netinvesment(deposito4, bunga, totaldeduction);
return 0;
}



