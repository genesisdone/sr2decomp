# sr2decomp

Readable C for **Saints Row 2 (PC)** functions that compile **byte for byte** to the retail game's code.

Every function listed in [FUNCTIONS.md](FUNCTIONS.md) has been compiled with Microsoft Visual C++ 2005
(cl 14.00.50727.42, `/O2`, with `/GL` + `/LTCG` where the original used link-time code generation) and its whole
body compared against the unpacked retail `SR2_pc.exe`. Only exact matches are published here: a function that
differs by a single byte stays out until it matches. Address operands and call targets are compared by the symbol
they resolve to, everything else literally.

This repository holds only hand-written C. It contains no part of the game: no executable, no assets, no
disassembly, no decompiler output, no inline assembly. To check the matches yourself you need your own copy of the
game.

## What is here

- `src/game/**/FUN_xxxxxxxx.c` - one certified function per file, named after its retail address.
- `src/game/player_movement_readable*.c` - player-movement functions, several per file (the line of each is in
  FUNCTIONS.md).
- Headers (`*_types.h`, `*_context.h`) - shared types and the compiler context some functions are built with.
  Context headers can contain other functions' C that is **not** certified on its own; only the functions listed in
  FUNCTIONS.md are claims.
- `FUNCTIONS.md` / `functions.json` - every certified function: address, size in bytes, the gate that certified it,
  and its source.

## How to read the claims

- Names are the retail addresses (`FUN_006c1cb0`). Struct and field names describe what the code does; no original
  Volition names are known.
- Many functions were compiled with link-time code generation, where the compiler picks custom register
  conventions. Their callees were supplied during matching by stand-ins that are not published here; the calling
  convention a file's declarations show is **not** claimed to be the original source's.
- A match is a statement about code bytes only. It does not mean a subsystem is complete or runnable.

## Progress

FUNCTIONS.md is regenerated from the matching certificates every time new functions are certified and pushed.

## License

MIT, see [LICENSE](LICENSE). Saints Row 2 is a trademark of its owners; this project is not affiliated with them.
