# Patchwork
A Kirby's Epic Yarn (Wii) custom code framework.

### Special Thanks
- EternityShack, for teaching me how to use Kamek
- Ninji, for Kamek

## Building
### Requirements
- NXP [CodeWarrior Special Edition][cw] for MPC55xx/MPC56xx v2.10
  - If this direct link doesn't work, the original page is
    [available on the Internet Archive][cwIA].
  - After installing it, you need `license.dat` from the installation root,
    and the DLL and EXE files inside `PowerPC_EABI_Tools/Command_Line_Tools`. Place all of these files in `deps/CodeWarrior/`.
  - Useful documentation is in `Help/Power_Arch_Build_Tools_Reference.chm`
    (or `Help/PDF/Power Architecture Build Tools Reference.pdf`)
- A build of the [Kamek](https://github.com/Treeki/Kamek) linker. Place it in `deps/Kamek/`.
- Python 3.7 or newer.

### Instructions
You will need [Riivolution](https://aerialx.github.io/rvlution.net/wiki/Riivolution/) to load these code mods.

If you just want to quickly test out the existing modifications, then you'll need to set up your patch xml to include these patches:
```xml
<memory offset="0x80001900" valuefile="/YourFolderName/Code/loader.bin"/>

<!-- The '4BFFB73D' address might change, but all you need to know is that it branches to a function that calls the loader (which is at address 0x80001900) -->
<memory offset='0x80006C40' value='4BFFB73D'/>
```

To generate `loader.bin`, run `build_loader.py`. You will see the file in the `build/` folder.

To generate custom code, run `build_code.py`. This will compile and assemble any `.cpp` or `.S` files (excluding those related to the loader). The result will be a file called `RK5_{REGION}.bin`, where `{REGION}` is the region of your game, located in the `build/` folder.

> As of writing this, only "USA" is supported (and is hardcoded).

Once you've gotten your loader and custom code binaries generated, put them wherever your Riivolution and loader code specify. It's important that the location of `RK5_{REGION}.bin` matches what is specified by the loader - by default, this is in a directory called `/Code/`, though you can change it to whatever you want if you simply recompile.

## Notes
Currently, there is only support for the USv1 of Kirby's Epic Yarn (meaning that `{REGION}` will always be `USA`). I may consider supporting other regions/versions of the game in the future.

[cw]: http://cache.nxp.com/lgfiles/devsuites/PowerPC/CW55xx_v2_10_SE.exe?WT_TYPE=IDE%20-%20Debug,%20Compile%20and%20Build%20Tools&WT_VENDOR=FREESCALE&WT_FILE_FORMAT=exe&WT_ASSET=Downloads&fileExt=.exe
[cwIA]: http://web.archive.org/web/20160602205749/http://www.nxp.com/products/software-and-tools/software-development-tools/codewarrior-development-tools/downloads/special-edition-software:CW_SPECIALEDITIONS