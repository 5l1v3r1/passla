#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void duzenDegistir(char *dizi, int boy){
	srand(time(NULL));
	int i,a;
	char *temp;
	
	for(i=0;i<boy;i++){
		a=rand()%boy;
		*temp=dizi[i];
		dizi[i]=dizi[a];
		dizi[a]=*temp;
	}
	
	dizi[i+1]='\0';
}



int main(){
	
	setlocale(LC_ALL, "Turkish"); 
	srand((unsigned int)(time(NULL)));
	int k_sayi,i;
	char kucuk_harf[26]="abcdefghijklmnoprstuvwxyz";
	char buyuk_harf[26]="ABCDEFGHIJKLMNOPRSTUVWXYZ";
	char sayilar[11]="1234567890";
	char ozel_karakter[13]="!'^+%&/=?_*";
	char *pass, *p;
	char kontrol_buyuk, kontrol_sayi, kontrol_okarakter, secim, duzen;
	
	
	
	do{
	
	
	printf("Parola ka� karakterli olsun?: ");
	scanf("%d",&k_sayi);
	
	printf("B�y�k harf olsun mu? (y/n): ");
	scanf(" %c",&kontrol_buyuk);
	
	printf("Say� olsun mu? (y/n): ");
	scanf(" %c",&kontrol_sayi);
	
	printf("�zel karakter olsun mu?: ");
	scanf(" %c", &kontrol_okarakter);
	
	pass=(char *)malloc(k_sayi*sizeof(char));
	
	if(kontrol_buyuk=='y'&&kontrol_sayi=='y'&&kontrol_okarakter=='y'){
		
		for(i=0;i<k_sayi;i++){
		pass[i]=kucuk_harf[rand()%(sizeof kucuk_harf-1)];
		if(i>1){
			while(i%2==1){
				pass[i]=buyuk_harf[rand()%(sizeof buyuk_harf-1)];
				break;
			}
			
			while(i%3==2){
				pass[i]=sayilar[rand()%(sizeof sayilar-1)];
				break;
			}
			
			while(i%(k_sayi-2)==2){
				pass[i]=ozel_karakter[rand()%(sizeof ozel_karakter-1)];
				break;
			}
			
		}
		
	}
	}
	
	if(kontrol_buyuk=='n'&&kontrol_sayi=='y'){
		
		for(i=0;i<k_sayi;i++){
		pass[i]=kucuk_harf[rand()%(sizeof kucuk_harf-1)];
		if(i>1){
			
			while(i%3==2){
				pass[i]=sayilar[rand()%(sizeof sayilar-1)];
				break;
			}
			
		}
		
	}
	}
	
	if(kontrol_buyuk=='y'&&kontrol_sayi=='n'){
		
		for(i=0;i<k_sayi;i++){
		pass[i]=kucuk_harf[rand()%(sizeof kucuk_harf-1)];
		if(i>1){
			while(i%2==1){
				pass[i]=buyuk_harf[rand()%(sizeof buyuk_harf-1)];
				break;
			}
			
		}
		
	}
	}
	
	if(kontrol_buyuk=='n'&&kontrol_sayi=='n'){
		printf("Bu se�enek d���k g�venlikli parola olu�turacakt�r. Parolalar�n�zda b�y�k harf ve say�y� ihmal etmemelisiniz...\n");
		for(i=0;i<k_sayi;i++){
		pass[i]=kucuk_harf[rand()%(sizeof kucuk_harf-1)];
		
	}
	}
	
	
	
	
	pass[i]='\0'; // Son indisteki i�eri�i NULL'a e�itledim ki dizginin sonunu belirtelim.
	printf("\n\n==> Parolan�z: %s\n\n",pass);
	printf("Parola d�zenini de�i�tirmek ister misiniz? (y/n): ");
	scanf(" %c",&duzen);
	if(duzen=='y'){
		while(duzen=='y'){
			duzenDegistir(pass, k_sayi);
			printf("%s\n",pass);
			printf("Parola d�zenini de�i�tirmek ister misiniz? (y/n): ");
			scanf(" %c",&duzen);
		}
		
		
	}
	
	
	free(pass);
	printf("\nYeni parola olu�turmak ister misiniz? (y/n): ");
	scanf(" %c",&secim);
	
	if(secim=='n'){
		printf("\n\nParolalar�n�z� saklamay� ve s�kl�kla de�istirmeyi unutmay�n. G�r��mek �zere...\n\n");
	}
		
		
	}while(secim=='y');
	
	
	return 0;
}


