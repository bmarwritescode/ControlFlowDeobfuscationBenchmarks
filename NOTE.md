```
tigress --Verbosity=1 --Seed=114514 --Environment=x86_64:Linux:Gcc:4.6 \
      --Transform=RandomFuns \
         --RandomFunsName=SECRET \
         --Verbosity=5 \
         --RandomFunsFunctionCount=1 \
         --RandomFunsTrace=0 \
         --RandomFunsType=long \
         --RandomFunsInputSize=1 \
         --RandomFunsLocalStaticStateSize=1 \
         --RandomFunsGlobalStaticStateSize=0 \
         --RandomFunsLocalDynamicStateSize=0 \
         --RandomFunsGlobalDynamicStateSize=0 \
         --RandomFunsBoolSize=1 \
         --RandomFunsLoopSize=20 \
         --RandomFunsCodeSize=10 \
         --RandomFunsOutputSize=1 \
         --RandomFunsTimeCheckCount=0 \
         --RandomFunsActivationCodeCheckCount=0 \
         --RandomFunsActivationCode=42 \
         --RandomFunsPasswordCheckCount=0 \
         --RandomFunsPassword=secret \
         --RandomFunsFailureKind=segv \
      --out=6-input.c empty.c
```

```
tigress --Verbosity=1 --Seed=114514  --Environment=x86_64:Linux:Gcc:4.6 \
      --Transform=RandomFuns --RandomFunsName=SECRET \
         --RandomFunsType=long \
         --RandomFunsInputSize=1 \
         --RandomFunsLocalStaticStateSize=1 \
         --RandomFunsGlobalStaticStateSize=0 \
         --RandomFunsLocalDynamicStateSize=0 \
         --RandomFunsGlobalDynamicStateSize=0 \
         --RandomFunsOutputSize=1 \
         --RandomFunsCodeSize=0 \
      --out=6-answer.c empty.c
```