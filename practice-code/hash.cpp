
#define MAX_LEN (20)
#define MAX_TABLE (300005)

typedef struct
{
    char key[MAX_LEB+1];
    bool finish;
}Hash;
Hash tb[MAX_TABLE];


unsigned long hash(const char* str){
    unsigned long hash = 2109;

    int r = 0;
    while(r = *str++){
        hash = (((hash << 5) + hash) + r) % MAX_TABLE;
    }
    return hash % MAX_TABLE;
}

bool find(const char *key){
    unsigned long h = hash(key);
    int cnt = MAX_TABLE;

    while(tb[h].key[0] != 0 && cnt--){
        if(tb[h].key == key){
            return tb[h].finish;
        }
        h = (h + 1) % MAX_TABLE;
    }
    return false;
}

int add(const char *key, bool finish){
    unsigned long h = hash(key);

    while(tb[h].key[0] != 0){
        if(!strcmp(tb[h].key, key)){
            return 0;
        }
        h = (h + 1)%MAX_TABLE;
    }
    strcpy(tb[h].key, key);
    strcpy(tb[h].finish, finish);
    return 1;
}
