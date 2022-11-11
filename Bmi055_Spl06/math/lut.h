#ifndef __LUT_H
#define __LUT_H
/**
 * @brief sin函数的查找表
*/
static const float sinlut1[] = {
    0,0.012296,0.024589,0.036879,0.049164,0.061441,0.073708,0.085965,0.098208,0.11044,0.12265,0.13484,0.14702,0.15917,0.17129,0.18339,0.19547,0.20751,0.21952,0.2315,0.24345,0.25535,0.26722,0.27905,0.29084,0.30258,0.31427,0.32592,0.33752,0.34907,0.36057,0.37201,0.38339,0.39472,0.40599,0.41719,0.42834,0.43941,0.45043,0.46137,0.47224,0.48305,0.49378,0.50443,0.51501,0.52551,0.53593,0.54627,0.55653,0.5667,0.57679,0.58679,0.5967,0.60652,0.61625,0.62589,0.63543,0.64488,0.65423,0.66348,0.67263,0.68167,0.69062,0.69946,0.70819,0.71682,0.72534,0.73375,0.74205,0.75023,0.75831,0.76626,0.77411,0.78183,0.78944,0.79693,0.80429,0.81154,0.81866,0.82566,0.83254,0.83928,0.84591,0.8524,0.85876,0.865,0.8711,0.87708,0.88292,0.88862,0.89419,0.89963,0.90493,0.9101,0.91512,0.92001,0.92476,0.92937,0.93384,0.93816,0.94235,0.94639,0.95029,0.95405,0.95766,0.96113,0.96445,0.96763,0.97066,0.97354,0.97628,0.97887,0.98131,0.9836,0.98574,0.98774,0.98958,0.99128,0.99282,0.99422,0.99546,0.99656,0.9975,0.99829,0.99894,0.99943,0.99977,0.99996,1,0.99988,0.99962,0.9992,0.99863,0.99792,0.99705,0.99603,0.99486,0.99354,0.99207,0.99045,0.98868,0.98676,0.98469,0.98247,0.9801,0.97759,0.97493,0.97212,0.96916,0.96606,0.96281,0.95941,0.95587,0.95219,0.94836,0.94439,0.94028,0.93602,0.93162,0.92708,0.9224,0.91758,0.91263,0.90753,0.9023,0.89693,0.89142,0.88579,0.88001,0.87411,0.86807,0.8619,0.8556,0.84917,0.84261,0.83593,0.82911,0.82218,0.81512,0.80793,0.80062,0.7932,0.78565,0.77798,0.7702,0.7623,0.75428,0.74615,0.73791,0.72956,0.72109,0.71252,0.70384,0.69505,0.68616,0.67716,0.66806,0.65886,0.64956,0.64017,0.63067,0.62108,0.6114,0.60162,0.59176,0.5818,0.57176,0.56163,0.55141,0.54111,0.53073,0.52027,0.50973,0.49911,0.48842,0.47765,0.46682,0.45591,0.44493,0.43388,0.42277,0.4116,0.40036,0.38906,0.37771,0.36629,0.35483,0.3433,0.33173,0.32011,0.30843,0.29671,0.28495,0.27314,0.26129,0.2494,0.23748,0.22552,0.21352,0.20149,0.18943,0.17735,0.16523,0.15309,0.14093,0.12875,0.11655,0.10432,0.092088,0.079838,0.067576,0.055303,0.043022,0.030735,0.018443,0.0061479,-0.0061479,-0.018443,-0.030735,-0.043022,-0.055303,-0.067576,-0.079838,-0.092088,-0.10432,-0.11655,-0.12875,-0.14093,-0.15309,-0.16523,-0.17735,-0.18943,-0.20149,-0.21352,-0.22552,-0.23748,-0.2494,-0.26129,-0.27314,-0.28495,-0.29671,-0.30843,-0.32011,-0.33173,-0.3433,-0.35483,-0.36629,-0.37771,-0.38906,-0.40036,-0.4116,-0.42277,-0.43388,-0.44493,-0.45591,-0.46682,-0.47765,-0.48842,-0.49911,-0.50973,-0.52027,-0.53073,-0.54111,-0.55141,-0.56163,-0.57176,-0.5818,-0.59176,-0.60162,-0.6114,-0.62108,-0.63067,-0.64017,-0.64956,-0.65886,-0.66806,-0.67716,-0.68616,-0.69505,-0.70384,-0.71252,-0.72109,-0.72956,-0.73791,-0.74615,-0.75428,-0.7623,-0.7702,-0.77798,-0.78565,-0.7932,-0.80062,-0.80793,-0.81512,-0.82218,-0.82911,-0.83593,-0.84261,-0.84917,-0.8556,-0.8619,-0.86807,-0.87411,-0.88001,-0.88579,-0.89142,-0.89693,-0.9023,-0.90753,-0.91263,-0.91758,-0.9224,-0.92708,-0.93162,-0.93602,-0.94028,-0.94439,-0.94836,-0.95219,-0.95587,-0.95941,-0.96281,-0.96606,-0.96916,-0.97212,-0.97493,-0.97759,-0.9801,-0.98247,-0.98469,-0.98676,-0.98868,-0.99045,-0.99207,-0.99354,-0.99486,-0.99603,-0.99705,-0.99792,-0.99863,-0.9992,-0.99962,-0.99988,-1,-0.99996,-0.99977,-0.99943,-0.99894,-0.99829,-0.9975,-0.99656,-0.99546,-0.99422,-0.99282,-0.99128,-0.98958,-0.98774,-0.98574,-0.9836,-0.98131,-0.97887,-0.97628,-0.97354,-0.97066,-0.96763,-0.96445,-0.96113,-0.95766,-0.95405,-0.95029,-0.94639,-0.94235,-0.93816,-0.93384,-0.92937,-0.92476,-0.92001,-0.91512,-0.9101,-0.90493,-0.89963,-0.89419,-0.88862,-0.88292,-0.87708,-0.8711,-0.865,-0.85876,-0.8524,-0.84591,-0.83928,-0.83254,-0.82566,-0.81866,-0.81154,-0.80429,-0.79693,-0.78944,-0.78183,-0.77411,-0.76626,-0.75831,-0.75023,-0.74205,-0.73375,-0.72534,-0.71682,-0.70819,-0.69946,-0.69062,-0.68167,-0.67263,-0.66348,-0.65423,-0.64488,-0.63543,-0.62589,-0.61625,-0.60652,-0.5967,-0.58679,-0.57679,-0.5667,-0.55653,-0.54627,-0.53593,-0.52551,-0.51501,-0.50443,-0.49378,-0.48305,-0.47224,-0.46137,-0.45043,-0.43941,-0.42834,-0.41719,-0.40599,-0.39472,-0.38339,-0.37201,-0.36057,-0.34907,-0.33752,-0.32592,-0.31427,-0.30258,-0.29084,-0.27905,-0.26722,-0.25535,-0.24345,-0.2315,-0.21952,-0.20751,-0.19547,-0.18339,-0.17129,-0.15917,-0.14702,-0.13484,-0.12265,-0.11044,-0.098208,-0.085965,-0.073708,-0.061441,-0.049164,-0.036879,-0.024589,-0.012296,-0.00521596
};
static const uint8_t auchCRCLo[] = { //CRC_16低8位数据区
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
        0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
        0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
        0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
        0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
        0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
        0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
        0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
        0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
        0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
        0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
        0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
        0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
        0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
        0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
        0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
        0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
        0x43, 0x83, 0x41, 0x81, 0x80, 0x40};
static const uint8_t auchCRCHi[] = {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
        0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
        0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40};
static double ATAN_LUT[256] = {0.0000000000,0.0039215485,0.0078429764,0.0117641631,0.0156849881,0.0196053309,
                              0.0235250710,0.0274440882,0.0313622624,0.0352794736,0.0391956019,0.0431105278,
                              0.0470241318,0.0509362949,0.0548468980,0.0587558227,0.0626629506,0.0665681638,
                              0.0704713446,0.0743723758,0.0782711405,0.0821675224,0.0860614053,0.0899526737,
                              0.0938412126,0.0977269074,0.1016096438,0.1054893085,0.1093657884,0.1132389710,
                              0.1171087446,0.1209749978,0.1248376255,0.1286965013,0.1325515323,0.1364026044,
                              0.1402496096,0.1440924408,0.1479309912,0.1517651553,0.1555948280,0.1594199049,
                              0.1632402828,0.1670558588,0.1708665312,0.1746721990,0.1784727620,0.1822681208,
                              0.1860581771,0.1898428334,0.1936219929,0.1973955598,0.2011634395,0.2049255380,
                              0.2086817623,0.2124320205,0.2161762215,0.2199142752,0.2236460927,0.2273715857,
                              0.2310906672,0.2348032511,0.2385092525,0.2422085871,0.2459011721,0.2495869254,
                              0.2532657662,0.2569376146,0.2606023917,0.2642600199,0.2679104224,0.2715535237,
                              0.2751892491,0.2788175253,0.2824382800,0.2860514417,0.2896569404,0.2932547070,
                              0.2968446734,0.3004267728,0.3040009393,0.3075671084,0.3111252164,0.3146752558,
                              0.3182170002,0.3217505544,0.3252758042,0.3287926915,0.3323011594,0.3358011520,
                              0.3392926145,0.3427754932,0.3462497357,0.3497152904,0.3531721069,0.3566201360,
                              0.3600593294,0.3634896400,0.3669110217,0.3703234297,0.3737268255,0.3771211497,
                              0.3805063771,0.3838824615,0.3872493632,0.3906070437,0.3939554653,0.3972945915,
                              0.4006243869,0.4039448169,0.4072558481,0.4105574480,0.4138495853,0.4171322295,
                              0.4204053512,0.4236689219,0.4269229141,0.4301673014,0.4334020581,0.4366271598,
                              0.4398425828,0.4430483044,0.4462443029,0.4494305575,0.4526070482,0.4557737560,
                              0.4589306629,0.4620777516,0.4652150058,0.4683424102,0.4714599501,0.4745676117,
                              0.4776653824,0.4807532499,0.4838312032,0.4868992318,0.4899573263,0.4930054778,
                              0.4960436784,0.4990719209,0.5020901990,0.5050985071,0.5080968402,0.5110851942,
                              0.5140635659,0.5170319525,0.5199903521,0.5229387636,0.5258771863,0.5288056206,
                              0.5317240673,0.5346325278,0.5375310045,0.5404195003,0.5432980185,0.5461665634,
                              0.5490251398,0.5518737530,0.5547124091,0.5575411147,0.5603598769,0.5631687036,
                              0.5659676030,0.5687565842,0.5715356566,0.5743048302,0.5770641155,0.5798135236,
                              0.5825530662,0.5852827553,0.5880026035,0.5907126240,0.5934128303,0.5961032364,
                              0.5987838570,0.6014547069,0.6041158015,0.6067671569,0.6094087892,0.6120407151,
                              0.6146629519,0.6172755171,0.6198784285,0.6224717045,0.6250553640,0.6276294258,
                              0.6301939095,0.6327488350,0.6352942223,0.6378300921,0.6403564651,0.6428733625,
                              0.6453808058,0.6478788169,0.6503674179,0.6528466311,0.6553164793,0.6577769856,
                              0.6602281731,0.6626700655,0.6651026865,0.6675260602,0.6699402110,0.6723451634,
                              0.6747409422,0.6771275725,0.6795050796,0.6818734889,0.6842328261,0.6865831172,
                              0.6889243882,0.6912566655,0.6935799756,0.6958943450,0.6981998008,0.7004963699,
                              0.7027840796,0.7050629571,0.7073330300,0.7095943260,0.7118468729,0.7140906986,
                              0.7163258312,0.7185522990,0.7207701302,0.7229793534,0.7251799971,0.7273720900,
                              0.7295556609,0.7317307387,0.7338973524,0.7360555311,0.7382053040,0.7403467003,
                              0.7424797493,0.7446044805,0.7467209234,0.7488291075,0.7509290624,0.7530208178,
                              0.7551044035,0.7571798492,0.7592471847,0.7613064400,0.7633576449,0.7654008294,
                              0.7674360235,0.7694632573,0.7714825607,0.7734939638,0.7754974968,0.7774931897,
                              0.7794810727,0.7814611759,0.7834335294,0.7853981634};
static const float atan_Table[] = {0,0.0122952420509702,0.0245867678087946,0.0368708677155162,0.0491438456530697,
                            0.0614020255872662,0.0736417581213437,0.0858594269301211,0.0980514550467904,
                            0.110214310975599,0.122344514605099,0.134438642898259,0.146493335337505,
                            0.158505299104705,0.170471313978134,0.182388236930630,0.194253006415351,
                            0.206062646327814,0.217814269635179,0.229505081666030,0.241132383056141,
                            0.252693572347948,0.264186148243559,0.275607711513203,0.286955966562942,
                            0.298228722667327,0.309423894874343,0.320539504591576,0.331573679863911,
                            0.342524655354374,0.353390772040770,0.364170476641786,0.374862320786961,
                            0.385464959945598,0.395977152130165,0.406397756390103,0.416725731112139,
                            0.426960132143321,0.437100110752938,0.447144911449356,0.457093869667545,
                            0.466946409342762,0.476702040385418,0.486360356071690,0.495921030363898,
                            0.505383815174058,0.514748537583410,0.524015097030038,0.533183462476015,
                            0.542253669564794,0.551225817778859,0.560100067606915,0.568876637729199,
                            0.577555802228767,0.586137887835925,0.594623271212290,0.603012376280323,
                            0.611305671603504,0.619503667821753,0.627606915146088,0.635616000915969,
                            0.643531547222243,0.651354208598135,0.659084669780240,0.666723643541047,
                            0.674271868594154,0.681730107572906,0.689099145082905,0.696379785828501,
                            0.703572852813076,0.710679185612716,0.717699638722595,0.724635079975212,
                            0.731486389029422,0.738254455929067,0.744940179729832,0.751544467192861,
                            0.758068231543560,0.764512391293911,0.770877869126556,0.777165590838870,
                            0.783376484345163,0.789511478735160,0.795571503386839,0.801557487131743,
                            0.807470357470842,0.813311039839049,0.819080456916485,0.824779527984639,
                            0.830409168325548,0.835970288662195,0.841463794638329,0.846890586335952,
                            0.852251557828760,0.857547596769881,0.862779584012263,0.867948393260148,
                            0.873054890750092,0.878099934960047,0.883084376345069,0.888009057098268,
                            0.892874810935660,0.897682462903624,0.902432829207749,0.907126717061845,
                            0.911764924556007,0.916348240542616,0.920877444539229,0.925353306647359,
                            0.929776587486179,0.934148038140232,0.938468400120274,0.942738405336406,
                            0.946958776082706,0.951130225032606,0.955253455244275,0.959329160175350,
                            0.963358023706330,0.967340720172047,0.971277914400605,0.975170261759239,
                            0.979018408206568,0.982822990350744,0.986584635513017,0.990303961796286,
                            0.993981578158197,0.997618084488404,1.00121407168961,1.00477012176205,
                            1.00828680789104,1.01176469453735,1.01520433753004,1.01860628416149,
                            1.02197107328446,1.02529923541072,1.02859129281134,1.03184775961806,
                            1.03506914192583,1.03825593789624,1.04140863786156,1.04452772442940,
                            1.04761367258773,1.05066694981011,1.05368801616104,1.05667732440136,
                            1.05963532009343,1.06256244170613,1.06545912071953,1.06832578172908,
                            1.07116284254940,1.07397071431735,1.07674980159462,1.07950050246941,
                            1.08222320865749,1.08491830560235,1.08758617257450,1.09022718276983,
                            1.09284170340698,1.09543009582380,1.09799271557269,1.10052991251490,
                            1.10304203091376,1.10552940952681,1.10799238169673,1.11043127544124,
                            1.11284641354176,1.11523811363089,1.11760668827878,1.11995244507823,
                            1.12227568672868,1.12457671111890,1.12685581140861,1.12911327610878,
                            1.13134938916077,1.13356443001433,1.13575867370434,1.13793239092635,
                            1.14008584811100,1.14221930749724,1.14433302720430,1.14642726130266,
                            1.14850225988371,1.15055826912836,1.15259553137446,1.15461428518317,
                            1.15661476540412,1.15859720323958,1.16056182630744,1.16250885870320,
                            1.16443852106082,1.16635103061260,1.16824660124796,1.17012544357122,
                            1.17198776495837,1.17383376961287,1.17566365862042,1.17747763000277,
                            1.17927587877064,1.18105859697562,1.18282597376115,1.18457819541269,
                            1.18631544540684,1.18803790445969,1.18974575057426,1.19143915908708,
                            1.19311830271396,1.19478335159485,1.19643447333802,1.19807183306329,
                            1.19969559344460,1.20130591475172,1.20290295489123,1.20448686944678,
                            1.20605781171855,1.20761593276207,1.20916138142623,1.21069430439071,
                            1.21221484620263,1.21372314931259,1.21521935410999,1.21670359895777,
                            1.21817602022647,1.21963675232767,1.22108592774684,1.22252367707556,
                            1.22395012904316,1.22536541054779,1.22676964668689,1.22816296078718,
                            1.22954547443398,1.23091730750009,1.23227857817411,1.23362940298826,
                            1.23496989684562,1.23630017304699,1.23762034331717,1.23893051783077,
                            1.24023080523762,1.24152131268760,1.24280214585512,1.24407340896314,
                            1.24533520480668,1.24658763477599,1.24783079887926,1.24906479576494,
                            1.25028972274359,1.25150567580945,1.25271274966152,1.25391103772431,
                            1.25510063216819,1.25628162392942,1.25745410272975,1.25861815709571,
                            1.25977387437759,1.26092134076800,1.26206064132017,1.26319185996586,
                            1.26431507953302,1.26543038176306,1.26653784732791,1.26763755584667,
                            1.26872958590202,1.26981401505637,1.27089091986766,1.27196037590493,
                            1.27302245776356,1.27407723908034,1.27512479254817,1.27616518993056,
                            1.27719850207587,1.27822479893127,1.27924414955653,1.28025662213747,
                            1.28126228399926,1.28226120161945,1.28325344064078,1.28423906588375,
                            1.28521814135904,1.28619073027962,1.28715689507274,1.28811669739164,
                            1.28907019812711,1.29001745741886,1.29095853466662,1.29189348854114,
                            1.29282237699498,1.29374525727304,1.29466218592305,1.29557321880574,
                            1.29647841110496,1.29737781733752,1.29827149136297,1.29915948639313,
                            1.30004185500151,1.30091864913253,1.30178992011066,1.30265571864931,
                            1.30351609485965,1.30437109825927,1.30522077778063,1.30606518177948,
                            1.30690435804304,1.30773835379811,1.30856721571903,1.30939098993548,
                            1.31020972204020,1.31102345709655,1.31183223964595,1.31263611371522,
                            1.31343512282378,1.31422930999073,1.31501871774185,1.31580338811642,
                            1.31658336267400,1.31735868250110,1.31812938821764,1.31889551998346,
                            1.31965711750457,1.32041422003947,1.32116686640519,1.32191509498336,
                            1.32265894372616,1.32339845016213,1.32413365140193,1.32486458414398,
                            1.32559128468008,1.32631378890083,1.32703213230105,1.32774634998509,
                            1.32845647667208,1.32916254670102,1.32986459403591,1.33056265227067,
                            1.33125675463412,1.33194693399477,1.33263322286556,1.33331565340862,
                            1.33399425743980,1.33466906643327,1.33534011152597,1.33600742352203,
                            1.33667103289706,1.33733096980251,1.33798726406978,1.33863994521445,
                            1.33928904244030,1.33993458464333,1.34057660041578,1.34121511804994,
                            1.34185016554208,1.34248177059616,1.34310996062760,1.34373476276692,
                            1.34435620386339,1.34497431048857,1.34558910893983,1.34620062524379,
                            1.34680888515974,1.34741391418301,1.34801573754826,1.34861438023272,
                            1.34920986695945,1.34980222220046,1.35039147017984,1.35097763487686,
                            1.35156074002895,1.35214080913471,1.35271786545686,1.35329193202513,
                            1.35386303163909,1.35443118687101,1.35499642006861,1.35555875335779,
                            1.35611820864534,1.35667480762161,1.35722857176308,1.35777952233500,
                            1.35832768039390,1.35887306679011,1.35941570217024,1.35995560697962,
                            1.36049280146470,1.36102730567540,1.36155913946750,1.36208832250490,
                            1.36261487426191,1.36313881402549,1.36366016089747,1.36417893379672,
                            1.36469515146129,1.36520883245055,1.36571999514727,1.36622865775968,
                            1.36673483832352,1.36723855470403,1.36773982459791,1.36823866553532,
                            1.36873509488178,1.36922912984003,1.36972078745198,1.37021008460050,
                            1.37069703801125,1.37118166425451,1.37166397974691,1.37214400075320,
                            1.37262174338800,1.37309722361745,1.37357045726094,1.37404145999273,
                            1.37451024734364,1.37497683470259,1.37544123731824,1.37590347030057,
                            1.37636354862239,1.37682148712092,1.37727730049925,1.37773100332788,
                            1.37818261004614,1.37863213496368,1.37907959226190,1.37952499599534,
                            1.37996836009310,1.38040969836020,1.38084902447895,1.38128635201030,
                            1.38172169439515,1.38215506495565,1.38258647689652,1.38301594330629,
                            1.38344347715861,1.38386909131342,1.38429279851823,1.38471461140932,
                            1.38513454251293,1.38555260424642,1.38596880891947,1.38638316873523,
                            1.38679569579140,1.38720640208144,1.38761529949560,1.38802239982204,
                            1.38842771474794,1.38883125586050,1.38923303464808,1.38963306250114,
                            1.39003135071336,1.39042791048259,1.39082275291190,1.39121588901050,
                            1.39160732969481,1.39199708578935,1.39238516802772,1.39277158705355,
                            1.39315635342140,1.39353947759774,1.39392096996176,1.39430084080638,
                            1.39467910033904,1.39505575868263,1.39543082587634,1.39580431187648,
                            1.39617622655740,1.39654657971225,1.39691538105383,1.39728264021542,
                            1.39764836675154,1.39801257013880,1.39837525977664,1.39873644498812,
                            1.39909613502069,1.39945433904696,1.39981106616539,1.40016632540112,
                            1.40052012570661,1.40087247596242,1.40122338497790,1.40157286149192,
                            1.40192091417351,1.40226755162261,1.40261278237072,1.40295661488159,
                            1.40329905755184,1.40364011871167,1.40397980662550,1.40431812949258,
                            1.40465509544766,1.40499071256157,1.40532498884191,1.40565793223360,
                            1.40598955061951,1.40631985182108,1.40664884359886,1.40697653365315,
                            1.40730292962452,1.40762803909445,1.40795186958585,1.40827442856361,
                            1.40859572343520,1.40891576155117,1.40923455020570,1.40955209663718,
                            1.40986840802866,1.41018349150842,1.41049735415050,1.41081000297518,
                            1.41112144494948,1.41143168698768,1.41174073595183,1.41204859865217,
                            1.41235528184771,1.41266079224662,1.41296513650674};

#endif
