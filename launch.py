import subprocess
import argparse

# Simple command line argument interface


def init_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Parses launch options")
    parser.add_argument("--dir", help="Set build directory",
                        action="store", default="build/win-x64")
    parser.add_argument("--test", help="Run tests",
                        action="store_true", default=False)
    return parser


def main():
    args = init_parser().parse_args()
    subprocess.run(["cmake", "-B", args.dir, "-S", "."])
    subprocess.run(["cmake", "--build", args.dir])

    if args.test:
        return 0
    else:
        # TODO: Figure out a name for the game
        subprocess.run([args.dir + "/bin/Debug/Game.exe"])


if __name__ == "__main__":
    main()
    exit(0)
