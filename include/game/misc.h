#include "types.h"
#include "gfl/gfl.h"

char* getEnemyNameByID(u32 enemyID);
void  copyEnemyNameByID(u32 enemyID, char* destStr);
void* getEnemyConstructorByID(u32 enemyID);
char* getLinkedEnemyNameByID(u32 enemyID);
char* getEnemyResPathByID(u32 enemyID);

void construct_array(void* dest, void* ctor, void* dtor, size_t structureSize, u32 numStructures);
void destroy_array(void* array, void* dtor, size_t structureSize, u32 numStructures);
