# Tigress Tool

This tool invokes `tigress` with configurations defined in `configs/` to generate obfuscated sample C files. 

Sample configuration:

```yaml
description: block-fission      # result directory name
params: ["--Seed=1"]            # global parameter
variants:
  - name: basic                 # obfucation variant name
    procedure:                  # parameters used in each iteration invoking tigress - the output would be the next input
      - ["--Transform=Flatten", "--FlattenSplitBasicBlocks=true", "--Functions=SECRET"]
      - ["--Transform=InitOpaque", "--Functions=SECRET", "--InitOpaqueCount=1", "--InitOpaqueStructs=list,array",
          "--Transform=AddOpaque", "--Functions=SECRET"]
```

## Install

Put the `tigress` folder in this directory. `run.py` will automatically set up environment variables needed.