#include <kamek/kamek_loader.h>

typedef void *(*GFL_Alloc_t) (s32 heapID, u32 size, s32 align);
typedef void (*GFL_Free_t) (void *buffer);

struct loaderFunctionsEx {
    loaderFunctions base;
    GFL_Alloc_t gflAlloc;
    GFL_Free_t gflFree;
};

void *allocAdapter(u32 size, bool isForCode, const loaderFunctions *funcs) {
    const loaderFunctionsEx *funcsEx = (const loaderFunctionsEx *)funcs;
    return funcsEx->gflAlloc(1, size, 0x20);
}
void freeAdapter(void *buffer, bool isForCode, const loaderFunctions *funcs) {
    const loaderFunctionsEx *funcsEx = (const loaderFunctionsEx *)funcs;
    funcsEx->gflFree(buffer);
}

const loaderFunctions functions_ntsc = {
    (OSReport_t) 0x806649C0,
    (OSFatal_t) 0x80666CB0,
    (DVDConvertPathToEntrynum_t) 0x8066FD30,
    (DVDFastOpen_t) 0x80670040,
    (DVDReadPrio_t) 0x80670410,
    (DVDClose_t) 0x806701D0,
    (sprintf_t) 0x80694500,
    (KamekAlloc_t) 0x80644060,
    (KamekFree_t) 0x806441C4
};

const loaderFunctionsEx functions_ex_ntsc = {
    {(OSReport_t) 0x806649C0,
    (OSFatal_t) 0x80666CB0,
    (DVDConvertPathToEntrynum_t) 0x8066FD30,
    (DVDFastOpen_t) 0x80670040,
    (DVDReadPrio_t) 0x80670410,
    (DVDClose_t) 0x806701D0,
    (sprintf_t) 0x80694500,
    allocAdapter,
    freeAdapter},
    (GFL_Alloc_t) 0x80644060,
    (GFL_Free_t) 0x806441C4
};

int loadIntoKEY();

kmCallDefCpp(0x80006C40, int, void) {
    loadIntoKEY();
    return 0;
}

int loadIntoKEY() {
    // just for ntscv1
    const loaderFunctionsEx* funcs = &functions_ex_ntsc;
    funcs->base.OSReport("Loading custom code for Kirby's Epic Yarn...\n");
    loadKamekBinaryFromDisc(&funcs->base, "/patchwork/RK5_USA.bin");
    funcs->base.OSReport("Finished loading custom code! Welcome to Patchwork!\n");
    return 1;
}





