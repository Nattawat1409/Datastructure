//Nattawat  Ruensumrit//
//66070503420//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SongNode {
    char songName[500];
    char artistName[500];
    int duration;
    struct SongNode* next;
} SongNode;

typedef struct Playlist {
    SongNode *front;
    SongNode *rear;
} Playlist;

void addSong(Playlist *playlist);
void playSong(Playlist *playlist);
void showPlaylist(Playlist *playlist);

int main() 
{
    char option[10];
    Playlist *playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->front = NULL;
    playlist->rear = NULL;
    
    while (1) {
        scanf("%s", option);
        if (strcmp("add", option) == 0) {
            addSong(playlist);
        } else if (strcmp("play", option) == 0) {
            playSong(playlist);
        } else if (strcmp("sum", option) == 0) {
            showPlaylist(playlist);
            break;
        } else {
            break;
        }
    }
    
    // Free dynamically allocated memory before exiting
    SongNode *current = playlist->front;
    while (current != NULL) 
    {
        SongNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(playlist);

    return 0;
}

void addSong(Playlist *playlist)
{
    SongNode *newNode = (SongNode*)malloc(sizeof(SongNode));
    scanf(" %[^\n]%*c", newNode->songName);
    scanf(" %[^\n]%*c", newNode->artistName);
    scanf("%d", &(newNode->duration));
    newNode->next = NULL;

    if (playlist->front == NULL && playlist->rear == NULL) {
        playlist->front = newNode;
        playlist->rear = newNode;
    } else {
        playlist->rear->next = newNode;
        playlist->rear = newNode;
    }
}

void playSong(Playlist *playlist) 
{
    SongNode *temp = playlist->front;
    if (playlist->front == NULL && playlist->rear == NULL) 
    {
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s by %s\n", temp->songName, temp->artistName);
    if (playlist->front->next == NULL) {
        playlist->front = NULL;
        playlist->rear = NULL;
    } else {
        playlist->front = playlist->front->next;
    }
    free(temp);
}

void showPlaylist(Playlist *playlist) 
{
    int totalTime = 0;
    if (playlist->front == NULL && playlist->rear == NULL) {
        printf("No songs in the playlist\n");
        return;
    }
    printf("Songs in the playlist:\n");
    SongNode *temp = playlist->front;
    while (temp != NULL) 
    {
        printf("%s by %s %d\n", temp->songName, temp->artistName, temp->duration);
        totalTime += temp->duration;
        temp = temp->next;
    }
    printf("Remaining Time: %d\n", totalTime);
}
