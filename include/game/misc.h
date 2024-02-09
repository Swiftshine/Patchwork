#include "types.h"
#include "gfl/gfl.h"

char* getEnemyNameByID(u32 enemyID);
void  copyEnemyNameByID(u32 enemyID, char* destStr);
void* getEnemyConstructorByID(u32 enemyID);
char* getLinkedEnemyNameByID(u32 enemyID);
char* getEnemyResPathByID(u32 enemyID);

