import sys

def calc_hash(filename: str):
    calculated_hash = 0
    for char in filename:
        # '% (2**32)' to ensure that it's 32-bits
        calculated_hash = (ord(char) + calculated_hash * 0x89) % (2**32)
    return calculated_hash

def main():
    arg_count = len(sys.argv) - 1
    if arg_count != 1:
        print("Usage: " + sys.argv[0] + " <filename>")
        sys.exit(1)

    print(hex(calc_hash(sys.argv[1])))


if __name__ == '__main__':
    main()