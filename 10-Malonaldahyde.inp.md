---
layout: default
title: 10-Malonaldahyde.inp
---


    <BeginTitle>

    Reactant energy:
    SCF : [13,1,1]               :: <SCF> = -.2656437482864332D+03 Hartree, -.7228537264563613D+04 eV, dD = 0.89D-04, DIIS = 0.12D-05

    Product energy:
    SCF : [13,1,1]               :: <SCF> = -.2656437482935356D+03 Hartree, -.7228537264756881D+04 eV, dD = 0.89D-04, DIIS = 0.12D-05

    E_Products=-265.64376 904
    E_Reactants-265.64376 262

    E_TS = 627.5095(265.62738-265.64376)=10.28 kcal/mol

    <EndTitle>

    <BeginOptions>

    Charge=0
    Multiplicity=1

    Clones=5
    NEBSpring=0.001
    RSL=0.25
    Grad=(TSSearch,PrimInt,NoGDIIS,NoBackTr,BiSect)
    MaxSTRE=0.03
    MaxANGLE=0.6

    NEBReactantEnergy=-.7228537264563613D+04
    NEBProductEnergy=-.7228537264756881D+04

    OutPut=xyz
    DebugAll=(MinDebug,CheckSums)

    Guess=SuperPos
    SCFMethod=(RH)
    BasisSets=(6-31G**-SPLIT)
    ModelChem=(HF)
    Accuracy=(Tight)
    SCFConvergence=(DIIS)

    <EndOptions>

    <BeginReactants>
     O    -1.2843303098672652     0.000    -0.8956055640465536
     C    -1.1539155180521243     0.000     0.4094332427882532
     C     0.0026999469917174     0.000     1.0901631211088485
     C     1.2781598622630863     0.000     0.3952822694770787
     O     1.3951765664154623     0.000    -0.8058678711305364
     H    -0.4186127974963088     0.000    -1.3013551221381254
     H    -2.1019374332625316     0.000     0.9181719964710650
     H    -0.0157214237087271     0.000     2.1627543540449734
     H     2.1726910967166915     0.000     1.0222035734249941
    <EndReactants>

    <BeginProducts>
     O    -1.3333893908563297    20.000    -0.8348772134051627
     C    -1.2413274152344023    20.000     0.3684337667416187
     C     0.0194778270966915    20.000     1.0896513980912717
     C     1.1899501578283767    20.000     0.4330905887121168
     O     1.3472392729736504    20.000    -0.8689812654444599
     H     0.4901174371640107    20.000    -1.2925897606102581
     H    -2.1486678712534504    20.000     0.9766827469741893
     H     0.0155129586229730    20.000     2.1623940463597631
     H     2.1272370236586324    20.000     0.9613483825809215
    <EndProducts>