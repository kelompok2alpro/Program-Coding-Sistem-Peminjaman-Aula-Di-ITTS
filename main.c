#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aula
{
    char namaPenyewa[100];
    char kodeBooking[100];
    char tanggalBooking[100];
    char hariBooking[100];
    char keterangan[100];
};

void penyewaanAula();
void informasiAula();
void pengembalian();
void hapusData();

    int main(){
    while (1)
    {
    int menu;
    printf("\t\t\t\t========== PROGRAM SISTEM PEMINJAMAN AULA DI ITTS ==========\t\t\t\t\n");
    printf("                             \n");
    printf("                             \n");
    printf("                             \n");
    printf("---------- Menu ----------\n");
    printf(" 1. Penyewaan Aula     \n");
    printf(" 2. Informasi Sewa      \n");
    printf(" 3. Pengembalian Masa Sewa    \n");
    printf(" 4. Hapus Data          \n");
    printf(" 5. Exit                \n");
    printf("-------------------------\n");
    printf("Masukan Pilihan anda[ 1 s.d. 4 ] = ");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        penyewaanAula();
        break;
    case 2:
        informasiAula();
        break;
    case 3:
        pengembalian();
        break;
    case 4:
        hapusData();
    case 5:
        return 0;
        break;

    default:
        break;
    }
  }
}

void penyewaanAula(){
    struct aula pinjamAula[100];
    memset(pinjamAula, 0, sizeof(pinjamAula));
    char str[500];
    printf("Tanggal Sewa : ");
    scanf(" %[^\n]s", &pinjamAula[0].tanggalBooking);
    printf("Berapa Hari : ");
    scanf(" %[^\n]s", &pinjamAula[0].hariBooking);
    printf("Nama Penyewa  : ");
    scanf(" %[^\n]s", &pinjamAula[0].namaPenyewa);
    printf("Kode Booking : ");
    scanf(" %[^\n]s", &pinjamAula[0].kodeBooking);
     printf("Keterangan : ");
    scanf(" %[^\n]s", &pinjamAula[0].keterangan);
    strcat(str, pinjamAula[0].tanggalBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].hariBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].namaPenyewa );
    strcat(str, "|");
    strcat(str, pinjamAula[0].kodeBooking );
    strcat(str, "|");
    strcat(str, pinjamAula[0].keterangan );
    strcat(str, "\n");
    FILE *fptr;
    fptr = fopen("data.txt", "a");
    fprintf(fptr, "%s", str);
    fclose(fptr);
}

void informasiAula(){
    struct aula informasiAula[100];
    char informasiPinjam[500];
    memset(informasiAula, 0, sizeof(informasiAula));
    FILE *fptr;
    char *hasil;
    fptr = fopen("data.txt", "r");
    int loop = 0;

    while (fgets(informasiPinjam, sizeof(informasiPinjam), fptr))
    {
    int loop2 = 0;
    int index[4];
        hasil = strchr(informasiPinjam, '|');
        while (hasil != NULL)
        {
            index[loop2] = hasil - informasiPinjam;
            hasil = strchr(hasil+1, '|');
            loop2++;
        }

        for (int i = 0; i < index[0]; i++)
        {
            informasiAula[loop].tanggalBooking[i] = informasiPinjam[i];
        }
        for (int i = 0; i < index[1] - index[0] - 1; i++)
        {
            informasiAula[loop].hariBooking[i] = informasiPinjam[i + index[0] + 1];
        }
        for (int i = 0; i < index[2] - index[1] - 1; i++)
        {
            informasiAula[loop].namaPenyewa[i] = informasiPinjam[i + index[1] + 1];
        }
        for (int i = 0; i < index[3] - index[2] - 1; i++)
        {
            informasiAula[loop].kodeBooking[i] = informasiPinjam[i + index[2] + 1];
        }
         for (int i = 0; i < strlen(informasiPinjam) - index[3] - 1; i++)
        {
            informasiAula[loop].keterangan[i] = informasiPinjam[i + index[3] + 1];
        }
        printf("\n");
        printf("Tanggal Booking : %s\n", informasiAula[loop].tanggalBooking);
        printf("Berapa Hari      : %s\n", informasiAula[loop].hariBooking);
        printf("Nama Penyewa   : %s\n", informasiAula[loop].namaPenyewa);
        printf("Kode Booking   : %s\n", informasiAula[loop].kodeBooking);
        printf("Keterangan      : %s\n", informasiAula[loop].keterangan);

          loop++;
    }

}

void pengembalian(){
  int loop = 0;
  int loop6 = 0;
  char *hasil;
  char searchData[50];
  char dataAula[100];
  struct aula cariData[50];
  FILE *fptr;
  fptr = fopen("data.txt", "r");
  memset(cariData, 0, sizeof(cariData));

  /*Menu Cari Data*/
	printf("-------------------- CARI DATA PENYEWA --------------------\n");
    printf("Masukan Kode Booking : ");
    scanf(" %[^\n]s", &searchData);
    /*End Menu Cari Data*/

  	while (fgets(dataAula, sizeof(dataAula), fptr)){
    int loop5 = 0;
  	  int loop2 = 0;
  	  int loop3 = 0;
  	  int loop4 = 0;
  	  int index2[4];

  	  	/*Mencari Index Dari Char '|'*/
  	  	hasil = strchr(dataAula, '|');
  	  	while(hasil != NULL){
  	  	  	index2[loop2] = hasil - dataAula;
  	  	  	hasil = strchr(hasil+1, '|');
  	  	  	loop2++;
  	  	}


  	  	  	for (int i = 0; i < index2[1] - index2[0] - 1; i++){
  	  	  	  	loop4 = 0;
  	  	  	  	for (int j = 0; j < strlen(searchData); j++){
  	  	  	  	  	if (tolower(dataAula[i+j+index2[0]+1]) == tolower(searchData[j])){
  	  	  	  	  	  	loop4++;
  	  	  	  	  	}
  	  	  	  	  	if (loop4 == strlen(searchData)){
  	  	  	  	  	  	loop3 = index2[0];
  	  	  	  	  	}
  	  	  	  	}
  	  	  	}


  	  	if (loop3 != index2[0]){/*Jika Tidak Data Sesuai Dengan Yang Dicari User*/
  	  	  	char str[500] = {""};
    	strcat(str, dataAula);

  	if (loop6 > 0){
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "a");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	}
  	if (loop6 == 0) /*Hapus Data Sebelumnya*/{
  	  /*Simpan String Hasil Penggabungan Ke data.txt*/
  	  FILE *fptr;
  	  fptr = fopen("data.txt", "w");
  	  fprintf(fptr,"%s", str);
  	  fclose(fptr);
  	  /*End Simpan String Hasil Penggabungan Ke data.txt*/
  	  loop6++;
  	}
  }else{  /*Jika NIP Sama Dengan Input User (Kosongkan File)*/
  	  }
  	  loop++;
  	}
  	fclose(fptr); /*Tutup File data.txt*/
		printf("Peminjaman Telah Selesai\n");
		printf("Tunggu Sebentar ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		sleep(1);
		printf(". ");
		system("cls");
}

void hapusData()
{
    FILE *fp;
    struct aula pinjamAula;
    char pinjamAula_hapus[100];
    int flag = 0;
    printf("Masukkan nama penyewa yang ingin dihapus: ");
    scanf("%s", pinjamAula_hapus);
    fp = fopen("aula.txt", "r");
    FILE *temp = fopen("data.txt", "w");
    while (fscanf(fp, "%s %s %d", pinjamAula.tanggalBooking, pinjamAula.hariBooking, pinjamAula.namaPenyewa, pinjamAula.kodeBooking, &pinjamAula.keterangan) != EOF)

        {
            fprintf(temp, "%s %s %d\n", pinjamAula.tanggalBooking, pinjamAula.hariBooking, pinjamAula.namaPenyewa, pinjamAula.kodeBooking, &pinjamAula.keterangan);
        }

        {
            flag = 1;
        }

    if (flag == 1)
    {
        printf("Data berhasil dihapus\n");
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
    fclose(fp);
    fclose(temp);
    remove("aula.txt");
    rename("data.txt", "aula.txt");
    printf("Tekan enter untuk kembali ke menu\n");
    getchar();
    getchar();
}



