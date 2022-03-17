# File with utilities for running Tigress to obfuscate benchmarks
import os
import subprocess

cmd = "tigress --Environment=x86_64:Linux:Gcc:4.6 {transforms} --out={out_path} {in_path}"

# Flatten transformations
flatten = "--Transform=Flatten --Functions={funcs}"
flatten_args = {
    "random": "--FlattenRandomizeBlocks",
    "split": "--FlattenSplitBasicBlocks",
    "goto": "--FlattenDispatch=goto",
}

# Opaque predicate transformations
opaque = "--Transform=InitOpaque --Functions={funcs} --Transform=AddOpaque --Functions={funcs}"
opaque_args = {
    # TODO: Add more than one opaque pred per function
    "call": "--AddOpaqueKinds=call",
    "bug": "--AddOpaqueKinds=bug",
    "true": "--AddOpaqueKinds=true",
    "junk": "--AddOpaqueKinds=junk",
    "fake": "--AddOpaqueKinds=fake",
    "question": "--AddOpaqueKinds=question",
    "all": "--AddOpaqueKinds=all",
}

# Checksum transformation
checksum = "--Transform=Checksum"
checksum_args = { #TODO: Add args
}

transform_cmds = {
    "flatten": (flatten, flatten_args),
    "opaque": (opaque, opaque_args),
    "checksum": (checksum, checksum_args),
}

SRC_PATH = 'unobfuscated'
TGT_PATH = 'obfuscated'

def main():
    if not os.path.exists(TGT_PATH):
        os.makedirs(TGT_PATH)

    transforms = [("flatten", []), ("opaque", [])]

    for fname in os.listdir(SRC_PATH):
        fpath = os.path.join(SRC_PATH, fname)
        for tform, args in transforms:
            opath = os.path.join(TGT_PATH, fname.replace(".c", "_{}.c".format(tform)))
            # TODO: other function names?
            tform_cmd = transform_cmds[tform][0].format(funcs="main")
            # TODO: handle multiple transforms at once?
            tigress_cmd = cmd.format(in_path=fpath, out_path=opath, transforms=tform_cmd)
            # TODO: add args!
            print(tigress_cmd)
            print("--")
            subprocess.check_output(tigress_cmd.split(" "))

if __name__ == "__main__":
    main()
