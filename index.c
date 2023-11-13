#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node untuk data karyawan
typedef struct Karyawan {
    char nama[50];
    char jabatan[20];
    int lama_bekerja;
    struct Karyawan* next;
} Karyawan;

// Node untuk data mobil
typedef struct Mobil {
    char nama_pemilik[50];
    char jenis_mobil[20];
    char warna[20];
    int lama_pengerjaan;
    char status[10];
    struct Mobil* next;
} Mobil;

// Fungsi untuk insertFirst() pada linked list karyawan
void insertFirst(Karyawan** head, char nama[], char jabatan[], int lama_bekerja) {
    Karyawan* newKaryawan = (Karyawan*)malloc(sizeof(Karyawan));
    strcpy(newKaryawan->nama, nama);
    strcpy(newKaryawan->jabatan, jabatan);
    newKaryawan->lama_bekerja = lama_bekerja;
    newKaryawan->next = *head;
    *head = newKaryawan;
}

// Fungsi untuk insertLast() pada linked list karyawan
void insertLast(Karyawan** head, char nama[], char jabatan[], int lama_bekerja) {
    Karyawan* newKaryawan = (Karyawan*)malloc(sizeof(Karyawan));
    strcpy(newKaryawan->nama, nama);
    strcpy(newKaryawan->jabatan, jabatan);
    newKaryawan->lama_bekerja = lama_bekerja;
    newKaryawan->next = NULL;

    if (*head == NULL) {
        *head = newKaryawan;
        return;
    }

    Karyawan* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newKaryawan;
}

// Fungsi untuk insertAt() pada linked list karyawan
void insertAt(Karyawan** head, char nama[], char jabatan[], int lama_bekerja, int position) {
    Karyawan* newKaryawan = (Karyawan*)malloc(sizeof(Karyawan));
    strcpy(newKaryawan->nama, nama);
    strcpy(newKaryawan->jabatan, jabatan);
    newKaryawan->lama_bekerja = lama_bekerja;
    newKaryawan->next = NULL;

    if (position == 1) {
        newKaryawan->next = *head;
        *head = newKaryawan;
        return;
    }

    Karyawan* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Posisi tidak valid.\n");
        free(newKaryawan);
        return;
    }

    newKaryawan->next = temp->next;
    temp->next = newKaryawan;
}

// Fungsi untuk menampilkan data karyawan
void showKaryawan(Karyawan* head) {
    Karyawan* temp = head;
    printf("Daftar Karyawan:\n");
    while (temp != NULL) {
        printf("Nama: %s, Jabatan: %s, Lama Bekerja: %d tahun\n", temp->nama, temp->jabatan, temp->lama_bekerja);
        temp = temp->next;
    }
    printf("\n");
}

// Fungsi untuk mencari karyawan berdasarkan nama
Karyawan* findKaryawan(Karyawan* head, char nama[]) {
    Karyawan* temp = head;
    while (temp != NULL) {
        if (strncmp(temp->nama, nama, sizeof(temp->nama)) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Fungsi untuk insertFirst() pada linked list mobil
void insertMobil(Mobil** head, char nama_pemilik[], char jenis_mobil[], char warna[], int lama_pengerjaan, char status[]) {
    Mobil* newMobil = (Mobil*)malloc(sizeof(Mobil));
    strcpy(newMobil->nama_pemilik, nama_pemilik);
    strcpy(newMobil->jenis_mobil, jenis_mobil);
    strcpy(newMobil->warna, warna);
    newMobil->lama_pengerjaan = lama_pengerjaan;
    strcpy(newMobil->status, status);
    newMobil->next = *head;
    *head = newMobil;
}

// Fungsi untuk menampilkan data mobil karyawan tertentu
void showMobil(Karyawan* karyawan, Mobil* head) {
    Mobil* temp = head;
    printf("Data Mobil Karyawan %s:\n", karyawan->nama);
    while (temp != NULL) {
        if (strcmp(temp->nama_pemilik, karyawan->nama) == 0) {
            printf("Nama Pemilik: %s, Jenis Mobil: %s, Warna: %s, Lama Pengerjaan: %d hari, Status: %s\n", temp->nama_pemilik, temp->jenis_mobil, temp->warna, temp->lama_pengerjaan, temp->status);
        }
        temp = temp->next;
    }
    printf("\n");
}

// Fungsi untuk menampilkan seluruh data
void showAll(Karyawan* karyawanHead, Mobil* mobilHead) {
    showKaryawan(karyawanHead);
    Mobil* temp = mobilHead;
    printf("Data Mobil Keseluruhan:\n");
    while (temp != NULL) {
        printf("Nama Pemilik: %s, Jenis Mobil: %s, Warna: %s, Lama Pengerjaan: %d hari, Status: %s\n", temp->nama_pemilik, temp->jenis_mobil, temp->warna, temp->lama_pengerjaan, temp->status);
        temp = temp->next;
    }
    printf("\n");
}

// Fungsi untuk deleteFirst() pada linked list mobil
void deleteFirst(Mobil** head) {
    if (*head == NULL) {
        printf("Tidak ada data mobil untuk dihapus.\n");
        return;
    }

    Mobil* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Fungsi untuk deleteLast() pada linked list mobil
void deleteLast(Mobil** head) {
    if (*head == NULL) {
        printf("Tidak ada data mobil untuk dihapus.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Mobil* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Fungsi untuk menghapus data mobil pada karyawan tertentu
void deleteMobil(Karyawan* karyawan, Mobil** head) {
    if (*head == NULL) {
        printf("Tidak ada data mobil untuk dihapus.\n");
        return;
    }

    Mobil* temp = *head;
    Mobil* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->nama_pemilik, karyawan->nama) == 0) {
            printf("Nama Pemilik: %s, Jenis Mobil: %s, Warna: %s, Lama Pengerjaan: %d hari, Status: %s\n", temp->nama_pemilik, temp->jenis_mobil, temp->warna, temp->lama_pengerjaan, temp->status);
            printf("Pilihan Hapus Data:\n");
            printf("1. Hapus Data Pertama\n");
            printf("2. Hapus Data Terakhir\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    deleteFirst(head);
                    printf("Data mobil berhasil dihapus.\n");
                    return;
                case 2:
                    deleteLast(head);
                    printf("Data mobil berhasil dihapus.\n");
                    return;
                default:
                    printf("Pilihan tidak valid.\n");
                    return;
            }
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Tidak ada data mobil untuk dihapus.\n");
}


// Fungsi untuk melakukan update pada hari dan status mobil
void updateHariStatus(Mobil** head) {
    Mobil* temp = *head;
    Mobil* prev = NULL;

    while (temp != NULL) {
        temp->lama_pengerjaan--;

        if (temp->lama_pengerjaan == 0) {
            strcpy(temp->status, "Selesai");
            printf("Mobil milik %s selesai dikerjakan.\n", temp->nama_pemilik);

            // Hapus mobil karena sudah selesai
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// ...

int main() {
    Karyawan* karyawanHead = NULL;
    Mobil* mobilHead = NULL;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Input Karyawan\n");
        printf("2. Show Karyawan\n");
        printf("3. Input Mobil\n");
        printf("4. Show Mobil Karyawan Tertentu\n");
        printf("5. Show All\n");
        printf("6. Delete\n");
        printf("7. Next Day\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char nama[50];
                char jabatan[20];
                int lama_bekerja;

                printf("Input Nama Karyawan: ");
                scanf("%s", nama);
                printf("Input Jabatan [Senior | Junior | Trainee]: ");
                scanf("%s", jabatan);
                printf("Input Lama Bekerja (tahun): ");
                scanf("%d", &lama_bekerja);

                if (strcmp(jabatan, "Senior") == 0) {
                    insertFirst(&karyawanHead, nama, jabatan, lama_bekerja);
                } else if (strcmp(jabatan, "Junior") == 0) {
                    insertLast(&karyawanHead, nama, jabatan, lama_bekerja);
                } else if (strcmp(jabatan, "Trainee") == 0) {
                    int position;
                    printf("Input Posisi untuk Trainee: ");
                    scanf("%d", &position);
                    insertAt(&karyawanHead, nama, jabatan, lama_bekerja, position);
                } else {
                    printf("Jabatan tidak valid.\n");
                }
                break;
            }
            case 2: {
                showKaryawan(karyawanHead);
                break;
            }
            case 3: {
                char nama_karyawan[50];
                char nama_pemilik[50];
                char jenis_mobil[20];
                char warna[20];
                int lama_pengerjaan;

                printf("Input Nama Karyawan yang akan Menangani Mobil: ");
                scanf("%s", nama_karyawan);

                Karyawan* karyawan = findKaryawan(karyawanHead, nama_karyawan);

                if (karyawan == NULL) {
                    printf("Karyawan tidak ditemukan.\n");
                    break;
                }

                printf("Data Karyawan:\n");
                printf("Nama: %s, Jabatan: %s, Lama Bekerja: %d tahun\n", karyawan->nama, karyawan->jabatan, karyawan->lama_bekerja);

                printf("Input Nama Pemilik Mobil: ");
                scanf("%s", nama_pemilik);
                printf("Input Jenis Mobil [Sedan | Hatchback | MPV | SUV]: ");
                scanf("%s", jenis_mobil);
                printf("Input Warna Mobil: ");
                scanf("%s", warna);
                printf("Input Lama Pengerjaan Mobil (hari): ");
                scanf("%d", &lama_pengerjaan);

                insertMobil(&mobilHead, nama_pemilik, jenis_mobil, warna, lama_pengerjaan, "Belum Selesai");
                printf("Data Mobil berhasil diinput.\n");
                break;
            }
            case 4: {
                char nama_karyawan[50];
                printf("Input Nama Karyawan: ");
                scanf("%s", nama_karyawan);

                Karyawan* karyawan = findKaryawan(karyawanHead, nama_karyawan);

                if (karyawan == NULL) {
                    printf("Karyawan tidak ditemukan.\n");
                    break;
                }

                showMobil(karyawan, mobilHead);
                break;
            }
            case 5: {
                showAll(karyawanHead, mobilHead);
                break;
            }
            case 6: {
                char nama_karyawan[50];
                printf("Input Nama Karyawan yang akan Dihapus Mobilnya: ");
                scanf("%s", nama_karyawan);

                Karyawan* karyawan = findKaryawan(karyawanHead, nama_karyawan);

                if (karyawan == NULL) {
                    printf("Karyawan tidak ditemukan.\n");
                    break;
                }

                deleteMobil(karyawan, &mobilHead);
                break;
            }

            case 7: { // Menambahkan case untuk Next Day
                updateHariStatus(&mobilHead);
                printf("Hari telah berlalu.\n");
                break;
            }

            case 0: {
                printf("Nama: <Nama Anda> - NPM: <NPM Anda> - Kelas: <Kelas Anda>\n");
                break;
            }
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 0);

    return 0;
}
