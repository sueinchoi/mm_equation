[ PROB ]

DDI model

# PBPK model of Drug A
# PBPK model of Drug B
# No metabolite included

[ SET ] end = 24, delta = 0.25

[ CMT ]
D     //; dose
Di    //; Index drug dose
Aad   //; adipose
Abo   //; bone
Abr   //; brain
Agu   //; gut
Ahe   //; heart
Aki   //; kidney
Ali   //; liver
Alu   //; lung
Amu   //; muscle
Ask   //; skin
Asp   //; spleen
Ave   //; venous blood
Aar   //; arterial blood
Are    //; rest of body

Aad_i   //; adipose
Abo_i   //; bone
Abr_i   //; brain
Agu_i   //; gut
Ahe_i   //; heart
Aki_i   //; kidney
Ali_i   //; liver
Alu_i   //; lung
Amu_i   //; muscle
Ask_i   //; skin
Asp_i   //; spleen
Ave_i   //; venous blood
Aar_i   //; arterial blood
Are_i   //; rest of body

[ PARAM ]


//! Environmental factors

WT = 70	// WT (kg)


//* Parameter without mentioning ref : Reference - kdeg_ref.PDF
kdeg_1a2    =  0.018    //  Degradation rate of CYP1A2 in the liver (/h)
kdeg_2a6     = 0.026    // !not used yet
kdeg_2b6    =  0.0258    // Degradation rate of CYP2B6 in the liver (/h) (PMID: 29921509)
kdeg_2c8    =  0.032     // Degradation rate of CYP2C8 in the liver (/h)
kdeg_2c9    =  0.0067    // Degradation rate of CYP2C9 in the liver (/h)
kdeg_2c19   =  0.027    // Degradation rate of CYP2C19 in the liver (/h)
kdeg_2d6    =  0.015    // Degradation rate of CYP2D6 in the liver (/h)
kdeg_3a4    =  0.0158  //Degradation rate of CYP3A4 in the liver (/h) (3A4 Sugiyama)
kdeg_3a5    =  0.019  //! Not used yet
kdeg_3a4_intestine = 0.029 // Degradation rate of CYP3A4 in the instestine (/h) (3A4 Sugiyama)


Abundance_1a2 = 39  // pmol/mg mic
Abundance_2c8 = 22.4  // pmol/mg mic
Abundance_2c9 = 61  // pmol/mg mic
Abundance_2c19 = 11  // pmol/mg mic
Abundance_2d6 = 12.6  // pmol/mg mic
Abundance_3a4 = 93  // pmol/mg mic
Abundance_ugt1a4 = 58  // pmol/mg mic
Abundance_ugt2b7 = 82.9  // pmol/mg mic

Abundance_3a4_intestine = 62.4 // nmol

//! Fractional tissue volumes

FVad = 0.213     //; adipose
FVbo = 0.0856   //; bone
FVbr = 0.02      //; brain
FVgu = 0.0171    //; gut
FVhe = 0.0047    //; heart
FVki = 0.0044    //; kidney
FVli = 0.021     //; liver
FVlu = 0.0076    //; lung
FVmu = 0.4       //; muscle
FVsk = 0.0371    //; skin
FVsp = 0.0026    //; spleen
FVve = 0.0514    //; venous
FVar = 0.0257    //; arterial
FVpl = 0.0424    //; plasma
FVrb = 0.0347    //; erythrocytes
FVre = 0.1098  //; rest of body (+testis)

// !Fractional tissue blood flows

FQad = 0.05      //; adipose
FQbo = 0.05      //; bone
FQbr = 0.12      //; brain
FQgu = 0.146462  //; gut
FQhe = 0.04      //; heart
FQki = 0.19      //; kidney
FQh  = 0.215385  //; hepatic (venous side)
FQlu = 1         //; lung
FQmu = 0.17      //; muscle
FQsk = 0.05      //; skin
FQsp = 0.017231  //; spleen
FQre = 0.114615  //; rest of body (+testis)


//! Physiological parameters

Qen      =   18  //Intestinal blood flow (L/h/70kg) (FDA)
Vh       =   1.5 // Liver volume (L)
Qpv      =   72.75  //portal vein
Vpv      =   0.07  //portal vein
MPPGL    =   45  //
HPGL     =    95 // Hepatocyte per g liver
LIV_wt   =   1529  //Liver weight
CO = 108.33   //; cardiac output (ml/s)
Qgut  = 17.13
V_intestine = 150  // mL from the CPT reference (Vu et all)


////////////////////////////////////////////////////////////////////////////

// ! Compound specific parameters

// * Partition coefficients
// TODO setting INPUT!

Kpad = 0.191  //; adipose
Kpbo = 0.374  //; bone
Kpbr = 0.606  //; brain
Kpgu = 0.578  //; gut
Kphe = 0.583  //; heart
Kpki = 0.597  //; kidney
Kpli = 0.570  //; liver
Kplu = 0.620  //; lung
Kpmu = 0.622  //; muscle
Kpsk = 0.600  //; skin
Kpsp = 0.591  //; spleen
Kpre = 0.600  // rest of body //! Same as skin

// * In vitro binding data & physicochemical
// TODO setting INPUT!

MW  = 100
DOSE = 100
fu   = 0.681  //; fraction unbound in plasma
CbCp    = 0.98  //; blood to plasma ratio
fumic = 0.9
fuhep = 1
fu_gut = 1

// * Clearances

CLint_1a2_ul = 1.03
CLint_2b6_ul = 0   //; fm2b6 = 0.21
CLint_2c8_ul = 2.82
CLint_2c9_ul = 1.05
CLint_2c19_ul = 0.44  //; fm2c19 = 0.06
CLint_2d6_ul = 13.5
CLint_3a4_ul = 13.97
CLint_other_ul = 16.35   //;
CLint_ul = 0
CLint_3a4_intestine = 1.21
Km_3a4 = 5.4 // uM


celltype = 0 // microsome(0), hepatocyte(1)

CLrenal   =  0   //; CLint renal (L/hr)
CLbile = 0





// * Absorption
// TODO setting INPUT!

Ka = 0.878     //; Ka (hr-1)
Fa = 1
Fg = 1


// * DDI parameter of IP
// TODO Show this part for the index drugs!

Ki_1a2_uM    =100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_1a2_uM    =100000  //Irreversible inhibition (uM)
kinact_1a2   =     0  //Irreversible inhibition (/h)
Emax_1a2     =     0  //Maximum induction effect to corresponding enzyme
EC50_1a2_uM  =100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)



Ki_2b6_uM   = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2b6_uM   = 100000  //Irreversible inhibition (uM)
kinact_2b6   =     0  //Irreversible inhibition (/h)
Emax_2b6     =     0  //Maximum induction effect to corresponding enzyme
EC50_2b6_uM = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c8_uM   =   10.9 //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c8_uM   = 100000  //Irreversible inhibition (uM)
kinact_2c8  =      0  //Irreversible inhibition (/h)
Emax_2c8    =      0  //Maximum induction effect to corresponding enzyme
EC50_2c8_uM = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c9_uM   = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c9_uM   = 100000  //Irreversible inhibition (uM)
kinact_2c9  =      0  //Irreversible inhibition (/h)
Emax_2c9    =      0  //Maximum induction effect to corresponding enzyme
EC50_2c9_uM = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c19_uM  = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c19_uM  = 100000  //Irreversible inhibition (uM)
kinact_2c19 =      0  //Irreversible inhibition (/h)
Emax_2c19   =      0  //Maximum induction effect to corresponding enzyme
EC50_2c19_uM= 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2d6_uM  =  100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2d6_uM  =  100000  //Irreversible inhibition (uM)
kinact_2d6   =     0  //Irreversible inhibition (/h)
Emax_2d6    =      0  //Maximum induction effect to corresponding enzyme
EC50_2d6_uM = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_3a4_uM  =     2.2 //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_3a4_uM  =  100000  //Irreversible inhibition (uM)
kinact_3a4  =      0  //Irreversible inhibition (/h)
Emax_3a4    =   18.7  //Maximum induction effect to corresponding enzyme
EC50_3a4_uM =   3.32  //Concentration causing half-maximal effect to corresponding enzyme (uM)


CLtype = 0 // 0 : by each enzyme, 1 : by microsome or hepatocyte (celltype)



//////////////////////////////////////////////////////////////////////

// ! Drug B specific parameter

// * Partition coefficients

Kplu_i = 5.952  //; lung
Kpad_i = 21.21  //; adipose
Kpbo_i = 21.532  //; bone
Kpbr_i = 18.938  //; brain
Kphe_i = 26.167  //; heart
Kpki_i = 24.096  //; kidney
Kpmu_i = 24.423  //; muscle
Kpsk_i = 16.814  //; skin
Kpsp_i = 26.597  //; spleen
Kpgu_i = 32.564  //; gut
Kpli_i = 46.029  //; liver
Kpre_i = 21.21  //; rest of body


// * In vitro binding data & physicochemical 

MWi    = 200
DOSEi  = 200
fu_i   = 0.16  //; fraction unbound in plasma
CbCp_i    = 0.82  //; blood to plasma ratio
fumic_i = 1
fuhep_i = 1
fu_gut_i = 1


// * Clearances

CLint_1a2_ul_i = 0
CLint_2b6_ul_i = 0   //; fm2b6 = 0.21
CLint_2c8_ul_i = 0
CLint_2c9_ul_i = 0
CLint_2c19_ul_i = 0  //; fm2c19 = 0.06
CLint_2d6_ul_i = 0
CLint_3a4_ul_i = 0
CLint_other_ul_i = 0   //;
CLint_ul_i = 0

celltype_i = 0 // microsome(0), hepatocyte(1)
CLtype_i = 0  // 0 : by each enzyme, 1 : by microsome or hepatocyte (celltype)

CLrenal_i   =  0   //; CLint renal (L/hr)
CLbile_i = 0


// * Absorption

Ka_i = 0.8     //; Ka (hr-1)
Fa_i  = 1.00     //; fraction absorbed
Fg_i = 1


// * DDI parameter of index drug

Ki_1a2_uM_i    =100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_1a2_uM_i    =100000  //Irreversible inhibition (uM)
kinact_1a2_i   =     0  //Irreversible inhibition (/h)
Emax_1a2_i     =     0  //Maximum induction effect to corresponding enzyme
EC50_1a2_uM_i  =100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2b6_uM_i   = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2b6_uM_i   = 100000  //Irreversible inhibition (uM)
kinact_2b6_i   =     0  //Irreversible inhibition (/h)
Emax_2b6_i     =     0  //Maximum induction effect to corresponding enzyme
EC50_2b6_uM_i = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c8_uM_i   = 100000 //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c8_uM_i   = 100000  //Irreversible inhibition (uM)
kinact_2c8_i  =      0  //Irreversible inhibition (/h)
Emax_2c8_i    =      0  //Maximum induction effect to corresponding enzyme
EC50_2c8_uM_i = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c9_uM_i   = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c9_uM_i   = 100000  //Irreversible inhibition (uM)
kinact_2c9_i  =      0  //Irreversible inhibition (/h)
Emax_2c9_i    =      0  //Maximum induction effect to corresponding enzyme
EC50_2c9_uM_i = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2c19_uM_i  = 100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2c19_uM_i  = 100000  //Irreversible inhibition (uM)
kinact_2c19_i =      0  //Irreversible inhibition (/h)
Emax_2c19_i   =      0  //Maximum induction effect to corresponding enzyme
EC50_2c19_uM_i= 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_2d6_uM_i  =  100000  //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_2d6_uM_i  =  100000  //Irreversible inhibition (uM)
kinact_2d6_i   =     0  //Irreversible inhibition (/h)
Emax_2d6_i    =      0  //Maximum induction effect to corresponding enzyme
EC50_2d6_uM_i = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)


Ki_3a4_uM_i  =  100000 //Inhibition rate constant of substrate to corresponding enzyme (uM)
KI_3a4_uM_i  =  100000  //Irreversible inhibition (uM)
kinact_3a4_i  =      0  //Irreversible inhibition (/h)
Emax_3a4_i    =      0  //Maximum induction effect to corresponding enzyme
EC50_3a4_uM_i = 100000  //Concentration causing half-maximal effect to corresponding enzyme (uM)

[ INIT ]

CYP1A2_ratio = 1
CYP2B6_ratio = 1
CYP2C8_ratio = 1
CYP2C9_ratio = 1
CYP2C19_ratio = 1
CYP2D6_ratio = 1
CYP3A4_ratio = 1
CYP3A4_intestine_ratio = 1


[ MAIN  ]


//! Physiology parameter
// *Total tissue volumes (L)
double Vad = WT*FVad;  // adipose
double Vbo = WT*FVbo;  // bone
double Vbr = WT*FVbr;  // brain
double Vgu = WT*FVgu;  // gut
double Vhe = WT*FVhe;  // heart
double Vki = WT*FVki;  // kidney
double Vli = WT*FVli;  // liver
double Vlu = WT*FVlu;  // lung
double Vmu = WT*FVmu;  // muscle
double Vsk = WT*FVsk;  // skin
double Vsp = WT*FVsp;  // spleen
double Vve = WT*FVve;  // venous blood
double Var = WT*FVar;  // arterial blood
double Vpl = WT*FVpl;  // plasma
double Vrb = WT*FVrb;  // erythrocytes
double Vre = WT*FVre;  // rest of body

double Vplas_ven = Vpl*Vve/(Vve + Var) 	;  // venous plasma
double Vplas_art = Vpl*Var/(Vve + Var) 	;  // arterial plasma

// *Total tissue blood flows (L/hr)

double QC  = CO/1000*60*60 ;  // cardiac output (L/hr)
double Qad = QC*FQad       ;  // adipose
double Qbo = QC*FQbo       ;  // bone
double Qbr = QC*FQbr       ;  // brain
double Qgu = QC*FQgu       ;  // gut
double Qhe = QC*FQhe       ;  // heart
double Qki = QC*FQki       ;  // kidney
double Qh  = QC*FQh        ;  // hepatic (venous side)
double Qsp = QC*FQsp       ;  // spleen
double Qha = Qh - Qgu - Qsp;  // hepatic artery
double Qlu = QC*FQlu       ;  // lung
double Qmu = QC*FQmu       ;  // muscle
double Qsk = QC*FQsk       ;  // skin
double Qre = QC*FQre       ;  // rest of body

// Enzyme concentration in liver, intestine 

double enzyme_1a2 = Abundance_1a2 * MPPGL * LIV_wt / Vh / 1000 / 1000;  // (uM)
double enzyme_2c8 = Abundance_2c8 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_2c9 = Abundance_2c9 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_2c19 = Abundance_2c19 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_2d6 = Abundance_2d6 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_3a4 = Abundance_3a4 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_ugt1a4 = Abundance_ugt1a4 * MPPGL * LIV_wt / Vh / 1000 / 1000; 
double enzyme_ugt2b7 = Abundance_ugt2b7 * MPPGL * LIV_wt / Vh  / 1000 / 1000;  
double enzyme_3a4_intestine = Abundance_3a4_intestine / V_intestine;  // (uM)


//! Compound specific 
//* PK 

double CLint_mic = CLint_ul /fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_hep = CLint_ul /fuhep * HPGL * LIV_wt * 60 / 1000/1000;
double CLint = celltype*CLint_hep + (1 - celltype)*CLint_mic;

//* PK 2

double CLint_other =  CLint_other_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_1a2 = CLint_1a2_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2b6 = CLint_2b6_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c8 = CLint_2c8_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c9 = CLint_2c9_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c19 = CLint_2c19_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2d6 = CLint_2d6_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_3a4 = CLint_3a4_ul / fumic * MPPGL * LIV_wt * 60 / 1000/1000;



//* DDI parameter

double Ki_1a2= Ki_1a2_uM * MW * fumic;    // ug/L
double KI_1a2= KI_1a2_uM * MW * fumic;    // ug/L
double EC50_1a2=EC50_1a2_uM * MW * fuhep;  // ug/L
double Ki_2b6= Ki_2b6_uM * MW * fumic;       // ug/L
double KI_2b6= KI_2b6_uM * MW * fumic;       // ug/L
double EC50_2b6=EC50_2b6_uM * MW * fuhep;    // ug/L
double Ki_2c8= Ki_2c8_uM * MW * fumic;     // ug/L
double KI_2c8= KI_2c8_uM * MW * fumic;     // ug/L
double EC50_2c8=EC50_2c8_uM * MW * fuhep;    // ug/L
double Ki_2c9= Ki_2c9_uM * MW * fumic;     // ug/L
double KI_2c9= KI_2c9_uM * MW * fumic;     // ug/L
double EC50_2c9=EC50_2c9_uM * MW * fuhep;    // ug/L
double Ki_2c19= Ki_2c19_uM * MW * fumic;     // ug/L
double KI_2c19= KI_2c19_uM * MW * fumic;     // ug/L
double EC50_2c19=EC50_2c19_uM * MW * fuhep;    // ug/L
double Ki_2d6= Ki_2d6_uM * MW * fumic;      // ug/L
double KI_2d6= KI_2d6_uM * MW * fumic;      // ug/L
double EC50_2d6=EC50_2d6_uM * MW * fuhep;     // ug/L
double Ki_3a4= Ki_3a4_uM * MW * fumic;     // ug/L
double KI_3a4= KI_3a4_uM * MW * fumic;     // ug/L
double EC50_3a4=EC50_3a4_uM * MW * fuhep;    // ug/L

//* Bioavailability

F_D = Fa * Fg_qgut * 1000;       // bioavailability of substrate // mg dose to ng/mL concentration
ALAG_D = 0.1;
/////////////////////////////////////////////////////////////////////////////////////////////////////

//! Index drug specific (Bupropion)

//* PK

double CLint_mic_i = CLint_ul_i /fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_hep_i = CLint_ul_i /fuhep_i * HPGL * LIV_wt * 60 / 1000/1000;
double CLint_i = celltype_i*CLint_hep_i + (1 - celltype_i)*CLint_mic_i;


double CLint_other_i =  CLint_other_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_1a2_i = CLint_1a2_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2b6_i = CLint_2b6_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c8_i = CLint_2c8_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c9_i = CLint_2c9_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2c19_i = CLint_2c19_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_2d6_i = CLint_2d6_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;
double CLint_3a4_i = CLint_3a4_ul_i / fumic_i * MPPGL * LIV_wt * 60 / 1000/1000;



//* DDI parameter

double Ki_1a2_i= Ki_1a2_uM_i * MWi * fumic_i;    // ug/L
double KI_1a2_i= KI_1a2_uM_i * MWi * fumic_i;    // ug/L
double EC50_1a2_i=EC50_1a2_uM_i * MWi * fuhep_i;  // ug/L
double Ki_2b6_i= Ki_2b6_uM_i * MWi * fumic_i;       // ug/L
double KI_2b6_i= KI_2b6_uM_i * MWi * fumic_i;       // ug/L
double EC50_2b6_i=EC50_2b6_uM_i * MWi * fuhep_i;    // ug/L
double Ki_2c8_i= Ki_2c8_uM_i * MWi * fumic_i;     // ug/L
double KI_2c8_i= KI_2c8_uM_i * MWi * fumic_i;     // ug/L
double EC50_2c8_i=EC50_2c8_uM_i * MWi * fuhep_i;    // ug/L
double Ki_2c9_i= Ki_2c9_uM_i * MWi * fumic_i;     // ug/L
double KI_2c9_i= KI_2c9_uM_i * MWi * fumic_i;     // ug/L
double EC50_2c9_i=EC50_2c9_uM_i * MWi * fuhep_i;    // ug/L
double Ki_2c19_i= Ki_2c19_uM_i * MWi * fumic_i;     // ug/L
double KI_2c19_i= KI_2c19_uM_i * MWi * fumic_i;     // ug/L
double EC50_2c19_i=EC50_2c19_uM_i * MWi * fuhep_i;    // ug/L
double Ki_2d6_i= Ki_2d6_uM_i * MWi * fumic_i;      // ug/L
double KI_2d6_i= KI_2d6_uM_i * MWi * fumic_i;      // ug/L
double EC50_2d6_i=EC50_2d6_uM_i * MWi * fuhep_i;     // ug/L
double Ki_3a4_i= Ki_3a4_uM_i * MWi * fumic_i;     // ug/L
double KI_3a4_i= KI_3a4_uM_i * MWi * fumic_i;     // ug/L
double EC50_3a4_i=EC50_3a4_uM_i * MWi * fuhep_i;    // ug/L

//*Bioavailability

F_Di = Fa_i * Fg_changed_i * 1000;     




[ ODE ]


//! IP drugs
// * Compound calculations for IP

double Cadipose  = Aad/Vad;  // adipose
double Cbone     = Abo/Vbo;  // bone
double Cbrain    = Abr/Vbr;  // brain
double Cgut      = Agu/Vgu;  // gut
double Cheart    = Ahe/Vhe;  // heart
double Ckidney   = Aki/Vki;  // kidney
double Cliver    = Ali/Vli;  // liver
double Clung     = Alu/Vlu;  // lung
double Cmuscle   = Amu/Vmu;  // muscle
double Cskin     = Ask/Vsk;  // skin
double Cspleen   = Asp/Vsp;  // spleen
double Cvenous   = Ave/Vve;  // venous blood
double Carterial = Aar/Var;  // arterial blood
double Crest     = Are/Vre;  // rest of body

// *Calculation of free concentrations - ug/mL

double Cliverfree  = Cliver*fu/Kpli;  // liver
double Ckidneyfree = Ckidney*fu; // kidney
double Cgutfree = Cgut*fu_gut;

// *ODE 
double Venous =
 Qad*(Cadipose/Kpad*CbCp) + Qbo*(Cbone/Kpbo*CbCp)   +
 Qbr*(Cbrain/Kpbr*CbCp)   + Qhe*(Cheart/Kphe*CbCp)  + Qki*(Ckidney/Kpki*CbCp) +
 Qh*(Cliver/Kpli*CbCp)    + Qmu*(Cmuscle/Kpmu*CbCp) + Qsk*(Cskin/Kpsk*CbCp) +
 Qre*(Crest/Kpre*CbCp);

double Absorption = Ka*D; //*F

dxdt_Aad = Qad*(Carterial - Cadipose/Kpad*CbCp);    // adipose
dxdt_Abo = Qbo*(Carterial - Cbone/Kpbo*CbCp);       // bone
dxdt_Abr = Qbr*(Carterial - Cbrain/Kpbr*CbCp);      // brain
dxdt_Agu = Absorption +
          Qgu*(Carterial - Cgut/Kpgu*CbCp);        // gut
dxdt_Ahe = Qhe*(Carterial - Cheart/Kphe*CbCp);      // heart
dxdt_Aki = Qki*(Carterial - Ckidney/Kpki*CbCp) -
          CLrenal*Ckidneyfree;                   // kidney
dxdt_Ali = Qha*Carterial +
          Qgu*(Cgut/Kpgu*CbCp) +
          Qsp*(Cspleen/Kpsp*CbCp) -
          Qh*(Cliver/Kpli*CbCp) -
          Cliverfree*TVCL;                      // liver
dxdt_Alu = Qlu*Cvenous - Qlu*(Clung/Kplu*CbCp);     // lung
dxdt_Amu = Qmu*(Carterial - Cmuscle/Kpmu*CbCp);     // muscle
dxdt_Ask = Qsk*(Carterial - Cskin/Kpsk*CbCp);       // skin
dxdt_Asp = Qsp*(Carterial - Cspleen/Kpsp*CbCp);     // testes
dxdt_Ave = Venous - Qlu*Cvenous;                  // venous blood
dxdt_Aar = Qlu*(Clung/Kplu*CbCp) - Qlu*Carterial;   // arterial blood
dxdt_Are = Qre*(Carterial - Crest/Kpre*CbCp);       // rest of body
dxdt_D   = - Absorption;                          // oral dosing


//* Clearance

double TVCL_total = CLint + CLbile;

// double TVCL_enzyme = CLint_1a2 / (1 + 1 / Ki_1a2_i * Cliverfree_i) * CYP1A2_ratio + CLint_2b6 / (1 + 1 / Ki_2b6_i * Cliverfree_i) * CYP2B6_ratio + CLint_2c8 / (1 + 1 / Ki_2c8_i * Cliverfree_i) * CYP2C8_ratio + CLint_2c9 / (1 + 1 / Ki_2c9_i * Cliverfree_i) * CYP2C9_ratio + CLint_2c19 / (1 + 1 / Ki_2c19_i * Cliverfree_i) * CYP2C19_ratio + CLint_2d6 / (1 + 1 / Ki_2d6_i * Cliverfree_i) * CYP2D6_ratio + CLint_3a4 / (1 + 1 / Ki_3a4_i * Cliverfree_i) * CYP3A4_ratio * Km_3a4 / (CYP3A4_ratio * enzyme_3a4 + Km_3a4) + CLint_other + CLbile;

double TVCL_enzyme = CLint_1a2 / (1 + 1 / Ki_1a2_i * Cliverfree_i) * CYP1A2_ratio + CLint_2b6 / (1 + 1 / Ki_2b6_i * Cliverfree_i) * CYP2B6_ratio + CLint_2c8 / (1 + 1 / Ki_2c8_i * Cliverfree_i) * CYP2C8_ratio + CLint_2c9 / (1 + 1 / Ki_2c9_i * Cliverfree_i) * CYP2C9_ratio + CLint_2c19 / (1 + 1 / Ki_2c19_i * Cliverfree_i) * CYP2C19_ratio + CLint_2d6 / (1 + 1 / Ki_2d6_i * Cliverfree_i) * CYP2D6_ratio + CLint_3a4 * Km_3a4 * CYP3A4_ratio / (CYP3A4_ratio * enzyme_3a4 + Km_3a4 * (1 + 1 / Ki_3a4_i * Cliverfree_i)) + CLint_other + CLbile;

double TVCL = (1 - CLtype) * TVCL_enzyme + CLtype * TVCL_total; 

double TVCL_intestine = CYP3A4_intestine_ratio * CLint_3a4_intestine * Km_3a4 / (CYP3A4_intestine_ratio * enzyme_3a4_intestine + Km_3a4 * (1 + 1 / Ki_3a4_i * Cgutfree_i));
double Fg_qgut = Qgut / (Qgut + TVCL_intestine * fu_gut);

//* Bioavailability

double Fg_changed  = 1 / ((CYP3A4_intestine_ratio * Km_3a4) / (CYP3A4_intestine_ratio * enzyme_3a4_intestine + Km_3a4) * (1 + Cgutfree_i / Ki_3a4_i) * (1 - Fg) + Fg) * Fg;    // FDA in vitro DDI Figure 7 // Wang et al// Sugiyama 3A4


//////////////////////////////////////////////////////////////////////////////////////////////////


//! Index drugs
//* Compound calculation

double Cadipose_i  = Aad_i/Vad;  // adipose
double Cbone_i     = Abo_i/Vbo;  // bone
double Cbrain_i    = Abr_i/Vbr;  // brain
double Cgut_i      = Agu_i/Vgu;  // gut
double Cheart_i    = Ahe_i/Vhe;  // heart
double Ckidney_i   = Aki_i/Vki;  // kidney
double Cliver_i    = Ali_i/Vh;  // liver
double Clung_i     = Alu_i/Vlu;  // lung
double Cmuscle_i   = Amu_i/Vmu;  // muscle
double Cskin_i     = Ask_i/Vsk;  // skin
double Cspleen_i   = Asp_i/Vsp;  // spleen
double Cvenous_i   = Ave_i/Vve;  // venous blood
double Carterial_i = Aar_i/Var;  // arterial blood
double Crest_i     = Are_i/Vre;  // rest of body

double Cliverfree_i  = Cliver_i*fu_i/Kpli_i;  // perfusion limited model
double Ckidneyfree_i = Ckidney_i*fu_i; // kidney
double Cgutfree_i    = Cgut_i*fu_gut_i;  // Amin Rostami-Hodjegan 2004 (FDA in vitro DDI figure 7)

double Venous_i =
  Qad*(Cadipose_i/Kpad_i*CbCp_i) + Qbo*(Cbone_i/Kpbo_i*CbCp_i)   +
  Qbr*(Cbrain_i/Kpbr_i*CbCp_i)   + Qhe*(Cheart_i/Kphe_i*CbCp_i)  + Qki*(Ckidney_i/Kpki_i*CbCp_i) +
  Qh*(Cliver_i/Kpli_i*CbCp_i)    + Qmu*(Cmuscle_i/Kpmu_i*CbCp_i) + Qsk*(Cskin_i/Kpsk_i*CbCp_i) +
  + Qre*(Crest_i/Kpre_i*CbCp_i);


//* ODE


double Absorption_i = Ka_i*Di; //*F

dxdt_Aad_i = Qad*(Carterial_i - Cadipose_i/Kpad_i*CbCp_i);    // adipose
dxdt_Abo_i = Qbo*(Carterial_i - Cbone_i/Kpbo_i*CbCp_i);       // bone
dxdt_Abr_i = Qbr*(Carterial_i - Cbrain_i/Kpbr_i*CbCp_i);      // brain
dxdt_Agu_i = Absorption_i +
           Qgu*(Carterial_i - Cgut_i/Kpgu_i*CbCp_i);        // gut
dxdt_Ahe_i = Qhe*(Carterial_i - Cheart_i/Kphe_i*CbCp_i);      // heart
dxdt_Aki_i = Qki*(Carterial_i - Ckidney_i/Kpki_i*CbCp_i) -
           CLrenal_i*Ckidneyfree_i;                   // kidney
dxdt_Ali_i = Qha*Carterial_i +
          Qgu*(Cgut_i/Kpgu_i*CbCp_i) +
          Qsp*(Cspleen_i/Kpsp_i*CbCp_i) -
          Qh*(Cliver_i/Kpli_i*CbCp_i) -
          Cliverfree_i*TVCLi;   
dxdt_Alu_i = Qlu*Cvenous_i - Qlu*(Clung_i/Kplu_i*CbCp_i);     // lung
dxdt_Amu_i = Qmu*(Carterial_i - Cmuscle_i/Kpmu_i*CbCp_i);     // muscle
dxdt_Ask_i = Qsk*(Carterial_i - Cskin_i/Kpsk_i*CbCp_i);       // skin
dxdt_Asp_i = Qsp*(Carterial_i - Cspleen_i/Kpsp_i*CbCp_i);     // spleen
dxdt_Ave_i = Venous_i - Qlu*Cvenous_i;                  // venous blood
dxdt_Aar_i = Qlu*(Clung_i/Kplu_i*CbCp_i) - Qlu*Carterial_i;   // arterial blood
dxdt_Are_i = Qre*(Carterial_i - Crest_i/Kpre_i*CbCp_i);       // rest of body
dxdt_Di   = - Absorption_i;                          // oral dosing

//* Clearance

double TVCL_total_i = CLint_i + CLbile_i;
double TVCL_enzyme_i = CLint_1a2_i / (1 + 1 / Ki_1a2 * Cliverfree) * CYP1A2_ratio + CLint_2b6_i / (1 + 1 / Ki_2b6 * Cliverfree) * CYP2B6_ratio + CLint_2c8_i / (1 + 1 / Ki_2c8 * Cliverfree) * CYP2C8_ratio + CLint_2c9_i / (1 + 1 / Ki_2c9 * Cliverfree) * CYP2C9_ratio + CLint_2c19_i / (1 + 1 / Ki_2c19 * Cliverfree) * CYP2C19_ratio + CLint_2d6_i / (1 + 1 / Ki_2d6 * Cliverfree) * CYP2D6_ratio + CLint_3a4_i / (1 + 1 / Ki_3a4 * Cliverfree) * CYP3A4_ratio + CLint_other_i + CLbile_i;


double TVCLi = (1 - CLtype_i) * TVCL_enzyme_i + CLtype_i * TVCL_total_i; 

//* Bioavailability

double Fg_changed_i  = 1 / (CYP3A4_intestine_ratio * (1 + Cgutfree / Ki_3a4) * (1 - Fg_i) + Fg_i) * Fg_i;    // FDA in vitro DDI Figure 7 // Wang et al// Sugiyama 3A4


///////////////////////////////////////////////////////////////////////////////////////////////////////////

//! Active enzyme ODE

dxdt_CYP1A2_ratio = kdeg_1a2 * (1 + Emax_1a2 * Cliverfree / (Cliverfree + EC50_1a2)) - (kdeg_1a2 + kinact_1a2 * Cliverfree / (KI_1a2 + Cliverfree)) * CYP1A2_ratio;  
dxdt_CYP2B6_ratio = kdeg_2b6 * (1 + Emax_2b6 * Cliverfree / (Cliverfree + EC50_2b6)) - (kdeg_2b6 + kinact_2b6 * Cliverfree / (KI_2b6 + Cliverfree)) * CYP2B6_ratio;
dxdt_CYP2C8_ratio = kdeg_2c8 * (1 + Emax_2c8 * Cliverfree / (Cliverfree + EC50_2c8)) - (kdeg_2c8 + kinact_2c8 * Cliverfree / (KI_2c8 + Cliverfree)) * CYP2C8_ratio;
dxdt_CYP2C9_ratio = kdeg_2c9 * (1 + Emax_2c9 * Cliverfree / (Cliverfree + EC50_2c9)) - (kdeg_2c9 + kinact_2c9 * Cliverfree / (KI_2c9 + Cliverfree)) * CYP2C9_ratio;
dxdt_CYP2C19_ratio = kdeg_2c19 * (1 + Emax_2c19 * Cliverfree / (Cliverfree + EC50_2c19)) - (kdeg_2c19 + kinact_2c19 * Cliverfree / (KI_2c19 + Cliverfree)) * CYP2C19_ratio;
dxdt_CYP2D6_ratio = kdeg_2d6 * (1 + Emax_2d6 * Cliverfree / (Cliverfree + EC50_2d6)) - (kdeg_2d6 + kinact_2d6 * Cliverfree / (KI_2d6 + Cliverfree)) * CYP2D6_ratio;
dxdt_CYP3A4_ratio = kdeg_3a4 * (1 + Emax_3a4 * Cliverfree / (Cliverfree + EC50_3a4)) - (kdeg_3a4 + kinact_3a4 * Cliverfree / (KI_3a4 + Cliverfree)) * CYP3A4_ratio;
dxdt_CYP3A4_intestine_ratio = kdeg_3a4_intestine * (1 + Emax_3a4 * Cgutfree / (Cgutfree + EC50_3a4)) - (kdeg_3a4_intestine + kinact_3a4 * Cgutfree / (KI_3a4 + Cgutfree)) * CYP3A4_intestine_ratio;




[ TABLE ]
Cvenous = Ave/Vve;
capture Cp = Cvenous/CbCp	; // venous plasma
capture Cp_i = Cvenous_i/CbCp_i ; 
capture TVCL_result = TVCL;
capture Fg_qgut_result = Fg_qgut;
[ CAPTURE ] Cp Cp_i Cvenous TVCL_result
