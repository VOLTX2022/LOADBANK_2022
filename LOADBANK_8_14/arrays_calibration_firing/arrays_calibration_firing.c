#include "arrays_calibration_firing.h"
double calibration_adc_array_volt[no_of_calibration_values_ch0]=    {966 ,1950 ,2198 ,2389  ,2580, 2733,3154,	3288 ,3880 ,	3919 };	
//double calibration_array_in_voltage[no_of_calibration_values_ch0]={51  ,101  ,121  ,141   ,	171,201  ,	205  };
double calibration_array_in_voltage[no_of_calibration_values_ch0]=  {51  ,102  ,116.5,126 ,137 ,142.9,164.5 ,	171  ,203  ,	205  };

double 	calibration_array_in_ampere[no_of_calibration_values_ch1]={1,2,3,4,5};
double calibration_adc_array_current[no_of_calibration_values_ch1]={1,2,3,4,5};

#if(use_flash_memory==without)

uint16_t firing_arr[firing_array_size]=//firing_array_size
{/*10000,
9997,
9994,
9991,
9987,
9984,
9981,
9978,
9975,
9972,
9969,
9965,
9962,
9959,
9956,
9953,
9950,
9947,
9943,
9940,
9937,
9934,
9931,
9928,
9925,
9921,
9918,
9915,
9912,
9909,
9906,
9903,
9899,
9896,
9893,
9890,
9887,
9884,
9881,
9877,
9874,
9871,
9868,
9865,
9862,
9859,
9856,
9852,
9849,
9846,
9843,
9840,
9837,
9834,
9830,
9827,
9824,
9821,
9818,
9815,
9812,
9808,
9805,
9802,
9799,
9796,
9793,
9790,
9786,
9783,
9780,
9777,
9774,
9771,
9768,
9764,
9761,
9758,
9755,
9752,
9749,
9746,
9743,
9739,
9736,
9733,
9730,
9727,
9724,
9721,
9717,
9714,
9711,
9708,
9705,
9702,
9699,
9695,
9692,
9689,
9686,
9683,
9680,
9677,
9674,
9670,
9667,
9664,
9661,
9658,
9655,
9652,
9648,
9645,
9642,
9639,
9636,
9633,
9630,
9626,
9623,
9620,
9617,
9614,
9611,
9608,
9605,
9601,
9598,
9595,
9592,
9589,
9586,
9583,
9580,
9576,
9573,
9570,
9567,
9564,
9561,
9558,
9554,
9551,
9548,
9545,
9542,
9539,
9536,
9533,
9529,
9526,
9523,
9520,
9517,
9514,
9511,
9508,
9504,
9501,
9498,
9495,
9492,
9489,
9486,
9483,
9479,
9476,
9473,
9470,
9467,
9464,
9461,
9458,
9454,
9451,
9448,
9445,
9442,
9439,
9436,
9433,
9429,
9426,
9423,
9420,
9417,
9414,
9411,
9408,
9405,
9401,
9398,
9395,
9392,
9389,
9386,
9383,
9380,
9376,
9373,
9370,
9367,
9364,
9361,
9358,
9355,
9352,
9348,
9345,
9342,
9339,
9336,
9333,
9330,
9327,
9323,
*/
10000,//////////////////
9320,
9317,
9314,
9311,
9308,
9305,
9302,
9299,
9295,
9292,
9289,
9286,
9283,
9280,
9277,
9274,
9271,
9268,
9264,
9261,
9258,
9255,
9252,
9249,
9246,
9243,
9240,
9236,
9233,
9230,
9227,
9224,
9221,
9218,
9215,
9212,
9209,
9205,
9202,
9199,
9196,
9193,
9190,
9187,
9184,
9181,
9178,
9174,
9171,
9168,
9165,
9162,
9159,
9156,
9153,
9150,
9147,
9143,
9140,
9137,
9134,
9131,
9128,
9125,
9122,
9119,
9116,
9113,
9109,
9106,
9103,
9100,
9097,
9094,
9091,
9088,
9085,
9082,
9079,
9075,
9072,
9069,
9066,
9063,
9060,
9057,
9054,
9051,
9048,
9045,
9042,
9038,
9035,
9032,
9029,
9026,
9023,
9020,
9017,
9014,
9011,
9008,
9005,
9001,
8998,
8995,
8992,
8989,
8986,
8983,
8980,
8977,
8974,
8971,
8968,
8965,
8961,
8958,
8955,
8952,
8949,
8946,
8943,
8940,
8937,
8934,
8931,
8928,
8925,
8922,
8918,
8915,
8912,
8909,
8906,
8903,
8900,
8897,
8894,
8891,
8888,
8885,
8882,
8879,
8876,
8873,
8869,
8866,
8863,
8860,
8857,
8854,
8851,
8848,
8845,
8842,
8839,
8836,
8833,
8830,
8827,
8824,
8821,
8818,
8814,
8811,
8808,
8805,
8802,
8799,
8796,
8793,
8790,
8787,
8784,
8781,
8778,
8775,
8772,
8769,
8766,
8763,
8760,
8757,
8754,
8750,
8747,
8744,
8741,
8738,
8735,
8732,
8729,
8726,
8723,
8720,
8717,
8714,
8711,
8708,
8705,
8702,
8699,
8696,
8693,
8690,
8687,
8684,
8681,
8678,
8675,
8672,
8669,
8665,
8662,
8659,
8656,
8653,
8650,
8647,
8644,
8641,
8638,
8635,
8632,
8629,
8626,
8623,
8620,
8617,
8614,
8611,
8608,
8605,
8602,
8599,
8596,
8593,
8590,
8587,
8584,
8581,
8578,
8575,
8572,
8569,
8566,
8563,
8560,
8557,
8554,
8551,
8548,
8545,
8542,
8539,
8536,
8533,
8530,
8527,
8524,
8521,
8518,
8515,
8512,
8509,
8506,
8503,
8500,
8497,
8494,
8491,
8488,
8485,
8482,
8479,
8476,
8473,
8470,
8467,
8464,
8461,
8458,
8455,
8452,
8449,
8446,
8443,
8440,
8437,
8434,
8431,
8428,
8425,
8422,
8419,
8416,
8413,
8410,
8407,
8404,
8401,
8398,
8395,
8392,
8389,
8386,
8383,
8380,
8377,
8374,
8371,
8369,
8366,
8363,
8360,
8357,
8354,
8351,
8348,
8345,
8342,
8339,
8336,
8333,
8330,
8327,
8324,
8321,
8318,
8315,
8312,
8309,
8306,
8303,
8300,
8297,
8294,
8292,
8289,
8286,
8283,
8280,
8277,
8274,
8271,
8268,
8265,
8262,
8259,
8256,
8253,
8250,
8247,
8244,
8241,
8239,
8236,
8233,
8230,
8227,
8224,
8221,
8218,
8215,
8212,
8209,
8206,
8203,
8200,
8197,
8194,
8192,
8189,
8186,
8183,
8180,
8177,
8174,
8171,
8168,
8165,
8162,
8159,
8156,
8154,
8151,
8148,
8145,
8142,
8139,
8136,
8133,
8130,
8127,
8124,
8121,
8119,
8116,
8113,
8110,
8107,
8104,
8101,
8098,
8095,
8092,
8089,
8087,
8084,
8081,
8078,
8075,
8072,
8069,
8066,
8063,
8060,
8058,
8055,
8052,
8049,
8046,
8043,
8040,
8037,
8034,
8032,
8029,
8026,
8023,
8020,
8017,
8014,
8011,
8008,
8006,
8003,
8000,
7997,
7994,
7991,
7988,
7985,
7983,
7980,
7977,
7974,
7971,
7968,
7965,
7962,
7960,
7957,
7954,
7951,
7948,
7945,
7942,
7940,
7937,
7934,
7931,
7928,
7925,
7922,
7920,
7917,
7914,
7911,
7908,
7905,
7902,
7900,
7897,
7894,
7891,
7888,
7885,
7882,
7880,
7877,
7874,
7871,
7868,
7865,
7863,
7860,
7857,
7854,
7851,
7848,
7846,
7843,
7840,
7837,
7834,
7831,
7829,
7826,
7823,
7820,
7817,
7814,
7812,
7809,
7806,
7803,
7800,
7797,
7795,
7792,
7789,
7786,
7783,
7781,
7778,
7775,
7772,
7769,
7767,
7764,
7761,
7758,
7755,
7752,
7750,
7747,
7744,
7741,
7738,
7736,
7733,
7730,
7727,
7724,
7722,
7719,
7716,
7713,
7710,
7708,
7705,
7702,
7699,
7697,
7694,
7691,
7688,
7685,
7683,
7680,
7677,
7674,
7671,
7669,
7666,
7663,
7660,
7658,
7655,
7652,
7649,
7646,
7644,
7641,
7638,
7635,
7633,
7630,
7627,
7624,
7622,
7619,
7616,
7613,
7611,
7608,
7605,
7602,
7599,
7597,
7594,
7591,
7588,
7586,
7583,
7580,
7577,
7575,
7572,
7569,
7566,
7564,
7561,
7558,
7556,
7553,
7550,
7547,
7545,
7542,
7539,
7536,
7534,
7531,
7528,
7525,
7523,
7520,
7517,
7515,
7512,
7509,
7506,
7504,
7501,
7498,
7495,
7493,
7490,
7487,
7485,
7482,
7479,
7476,
7474,
7471,
7468,
7466,
7463,
7460,
7457,
7455,
7452,
7449,
7447,
7444,
7441,
7439,
7436,
7433,
7430,
7428,
7425,
7422,
7420,
7417,
7414,
7412,
7409,
7406,
7404,
7401,
7398,
7396,
7393,
7390,
7388,
7385,
7382,
7379,
7377,
7374,
7371,
7369,
7366,
7363,
7361,
7358,
7355,
7353,
7350,
7347,
7345,
7342,
7339,
7337,
7334,
7331,
7329,
7326,
7324,
7321,
7318,
7316,
7313,
7310,
7308,
7305,
7302,
7300,
7297,
7294,
7292,
7289,
7286,
7284,
7281,
7279,
7276,
7273,
7271,
7268,
7265,
7263,
7260,
7258,
7255,
7252,
7250,
7247,
7244,
7242,
7239,
7237,
7234,
7231,
7229,
7226,
7223,
7221,
7218,
7216,
7213,
7210,
7208,
7205,
7203,
7200,
7197,
7195,
7192,
7190,
7187,
7184,
7182,
7179,
7177,
7174,
7171,
7169,
7166,
7164,
7161,
7158,
7156,
7153,
7151,
7148,
7146,
7143,
7140,
7138,
7135,
7133,
7130,
7128,
7125,
7122,
7120,
7117,
7115,
7112,
7110,
7107,
7104,
7102,
7099,
7097,
7094,
7092,
7089,
7087,
7084,
7081,
7079,
7076,
7074,
7071,
7069,
7066,
7064,
7061,
7059,
7056,
7053,
7051,
7048,
7046,
7043,
7041,
7038,
7036,
7033,
7031,
7028,
7026,
7023,
7021,
7018,
7016,
7013,
7010,
7008,
7005,
7003,
7000,
6998,
6995,
6993,
6990,
6988,
6985,
6983,
6980,
6978,
6975,
6973,
6970,
6968,
6965,
6963,
6960,
6958,
6955,
6953,
6950,
6948,
6945,
6943,
6940,
6938,
6935,
6933,
6931,
6928,
6926,
6923,
6921,
6918,
6916,
6913,
6911,
6908,
6906,
6903,
6901,
6898,
6896,
6893,
6891,
6889,
6886,
6884,
6881,
6879,
6876,
6874,
6871,
6869,
6866,
6864,
6862,
6859,
6857,
6854,
6852,
6849,
6847,
6844,
6842,
6840,
6837,
6835,
6832,
6830,
6827,
6825,
6823,
6820,
6818,
6815,
6813,
6810,
6808,
6806,
6803,
6801,
6798,
6796,
6794,
6791,
6789,
6786,
6784,
6782,
6779,
6777,
6774,
6772,
6770,
6767,
6765,
6762,
6760,
6758,
6755,
6753,
6750,
6748,
6746,
6743,
6741,
6738,
6736,
6734,
6731,
6729,
6727,
6724,
6722,
6719,
6717,
6715,
6712,
6710,
6708,
6705,
6703,
6701,
6698,
6696,
6693,
6691,
6689,
6686,
6684,
6682,
6679,
6677,
6675,
6672,
6670,
6668,
6665,
6663,
6661,
6658,
6656,
6654,
6651,
6649,
6647,
6644,
6642,
6640,
6637,
6635,
6633,
6630,
6628,
6626,
6623,
6621,
6619,
6616,
6614,
6612,
6609,
6607,
6605,
6603,
6600,
6598,
6596,
6593,
6591,
6589,
6586,
6584,
6582,
6580,
6577,
6575,
6573,
6570,
6568,
6566,
6564,
6561,
6559,
6557,
6554,
6552,
6550,
6548,
6545,
6543,
6541,
6539,
6536,
6534,
6532,
6529,
6527,
6525,
6523,
6520,
6518,
6516,
6514,
6511,
6509,
6507,
6505,
6502,
6500,
6498,
6496,
6493,
6491,
6489,
6487,
6485,
6482,
6480,
6478,
6476,
6473,
6471,
6469,
6467,
6464,
6462,
6460,
6458,
6456,
6453,
6451,
6449,
6447,
6445,
6442,
6440,
6438,
6436,
6434,
6431,
6429,
6427,
6425,
6423,
6420,
6418,
6416,
6414,
6412,
6409,
6407,
6405,
6403,
6401,
6398,
6396,
6394,
6392,
6390,
6388,
6385,
6383,
6381,
6379,
6377,
6375,
6372,
6370,
6368,
6366,
6364,
6362,
6359,
6357,
6355,
6353,
6351,
6349,
6347,
6344,
6342,
6340,
6338,
6336,
6334,
6332,
6329,
6327,
6325,
6323,
6321,
6319,
6317,
6315,
6312,
6310,
6308,
6306,
6304,
6302,
6300,
6298,
6296,
6293,
6291,
6289,
6287,
6285,
6283,
6281,
6279,
6277,
6274,
6272,
6270,
6268,
6266,
6264,
6262,
6260,
6258,
6256,
6254,
6252,
6249,
6247,
6245,
6243,
6241,
6239,
6237,
6235,
6233,
6231,
6229,
6227,
6225,
6223,
6221,
6218,
6216,
6214,
6212,
6210,
6208,
6206,
6204,
6202,
6200,
6198,
6196,
6194,
6192,
6190,
6188,
6186,
6184,
6182,
6180,
6178,
6176,
6174,
6172,
6170,
6168,
6166,
6164,
6161,
6159,
6157,
6155,
6153,
6151,
6149,
6147,
6145,
6143,
6141,
6139,
6137,
6135,
6133,
6131,
6129,
6127,
6125,
6124,
6122,
6120,
6118,
6116,
6114,
6112,
6110,
6108,
6106,
6104,
6102,
6100,
6098,
6096,
6094,
6092,
6090,
6088,
6086,
6084,
6082,
6080,
6078,
6076,
6074,
6072,
6070,
6069,
6067,
6065,
6063,
6061,
6059,
6057,
6055,
6053,
6051,
6049,
6047,
6045,
6043,
6042,
6040,
6038,
6036,
6034,
6032,
6030,
6028,
6026,
6024,
6022,
6021,
6019,
6017,
6015,
6013,
6011,
6009,
6007,
6005,
6003,
6002,
6000,
5998,
5996,
5994,
5992,
5990,
5988,
5987,
5985,
5983,
5981,
5979,
5977,
5975,
5973,
5972,
5970,
5968,
5966,
5964,
5962,
5960,
5959,
5957,
5955,
5953,
5951,
5949,
5948,
5946,
5944,
5942,
5940,
5938,
5937,
5935,
5933,
5931,
5929,
5927,
5926,
5924,
5922,
5920,
5918,
5916,
5915,
5913,
5911,
5909,
5907,
5906,
5904,
5902,
5900,
5898,
5897,
5895,
5893,
5891,
5889,
5888,
5886,
5884,
5882,
5881,
5879,
5877,
5875,
5873,
5872,
5870,
5868,
5866,
5865,
5863,
5861,
5859,
5858,
5856,
5854,
5852,
5851,
5849,
5847,
5845,
5844,
5842,
5840,
5838,
5837,
5835,
5833,
5831,
5830,
5828,
5826,
5824,
5823,
5821,
5819,
5818,
5816,
5814,
5812,
5811,
5809,
5807,
5806,
5804,
5802,
5800,
5799,
5797,
5795,
5794,
5792,
5790,
5788,
5787,
5785,
5783,
5782,
5780,
5778,
5777,
5775,
5773,
5772,
5770,
5768,
5767,
5765,
5763,
5762,
5760,
5758,
5757,
5755,
5753,
5752,
5750,
5748,
5747,
5745,
5743,
5742,
5740,
5738,
5737,
5735,
5734,
5732,
5730,
5729,
5727,
5725,
5724,
5722,
5720,
5719,
5717,
5716,
5714,
5712,
5711,
5709,
5708,
5706,
5704,
5703,
5701,
5699,
5698,
5696,
5695,
5693,
5691,
5690,
5688,
5687,
5685,
5684,
5682,
5680,
5679,
5677,
5676,
5674,
5672,
5671,
5669,
5668,
5666,
5665,
5663,
5662,
5660,
5658,
5657,
5655,
5654,
5652,
5651,
5649,
5648,
5646,
5644,
5643,
5641,
5640,
5638,
5637,
5635,
5634,
5632,
5631,
5629,
5628,
5626,
5625,
5623,
5621,
5620,
5618,
5617,
5615,
5614,
5612,
5611,
5609,
5608,
5606,
5605,
5603,
5602,
5600,
5599,
5597,
5596,
5594,
5593,
5592,
5590,
5589,
5587,
5586,
5584,
5583,
5581,
5580,
5578,
5577,
5575,
5574,
5572,
5571,
5569,
5568,
5567,
5565,
5564,
5562,
5561,
5559,
5558,
5556,
5555,
5554,
5552,
5551,
5549,
5548,
5546,
5545,
5544,
5542,
5541,
5539,
5538,
5536,
5535,
5534,
5532,
5531,
5529,
5528,
5527,
5525,
5524,
5522,
5521,
5520,
5518,
5517,
5515,
5514,
5513,
5511,
5510,
5508,
5507,
5506,
5504,
5503,
5502,
5500,
5499,
5497,
5496,
5495,
5493,
5492,
5491,
5489,
5488,
5487,
5485,
5484,
5483,
5481,
5480,
5479,
5477,
5476,
5475,
5473,
5472,
5471,
5469,
5468,
5467,
5465,
5464,
5463,
5461,
5460,
5459,
5457,
5456,
5455,
5453,
5452,
5451,
5449,
5448,
5447,
5446,
5444,
5443,
5442,
5440,
5439,
5438,
5437,
5435,
5434,
5433,
5431,
5430,
5429,
5428,
5426,
5425,
5424,
5423,
5421,
5420,
5419,
5417,
5416,
5415,
5414,
5412,
5411,
5410,
5409,
5407,
5406,
5405,
5404,
5403,
5401,
5400,
5399,
5398,
5396,
5395,
5394,
5393,
5391,
5390,
5389,
5388,
5387,
5385,
5384,
5383,
5382,
5381,
5379,
5378,
5377,
5376,
5375,
5373,
5372,
5371,
5370,
5369,
5367,
5366,
5365,
5364,
5363,
5362,
5360,
5359,
5358,
5357,
5356,
5355,
5353,
5352,
5351,
5350,
5349,
5348,
5347,
5345,
5344,
5343,
5342,
5341,
5340,
5339,
5337,
5336,
5335,
5334,
5333,
5332,
5331,
5329,
5328,
5327,
5326,
5325,
5324,
5323,
5322,
5321,
5319,
5318,
5317,
5316,
5315,
5314,
5313,
5312,
5311,
5310,
5308,
5307,
5306,
5305,
5304,
5303,
5302,
5301,
5300,
5299,
5298,
5297,
5296,
5295,
5293,
5292,
5291,
5290,
5289,
5288,
5287,
5286,
5285,
5284,
5283,
5282,
5281,
5280,
5279,
5278,
5277,
5276,
5275,
5274,
5273,
5272,
5271,
5270,
5269,
5268,
5267,
5266,
5265,
5264,
5262,
5261,
5260,
5259,
5258,
5257,
5257,
5256,
5255,
5254,
5253,
5252,
5251,
5250,
5249,
5248,
5247,
5246,
5245,
5244,
5243,
5242,
5241,
5240,
5239,
5238,
5237,
5236,
5235,
5234,
5233,
5232,
5231,
5230,
5229,
5228,
5228,
5227,
5226,
5225,
5224,
5223,
5222,
5221,
5220,
5219,
5218,
5217,
5216,
5216,
5215,
5214,
5213,
5212,
5211,
5210,
5209,
5208,
5207,
5206,
5206,
5205,
5204,
5203,
5202,
5201,
5200,
5199,
5199,
5198,
5197,
5196,
5195,
5194,
5193,
5192,
5192,
5191,
5190,
5189,
5188,
5187,
5186,
5186,
5185,
5184,
5183,
5182,
5181,
5181,
5180,
5179,
5178,
5177,
5176,
5176,
5175,
5174,
5173,
5172,
5171,
5171,
5170,
5169,
5168,
5167,
5167,
5166,
5165,
5164,
5163,
5163,
5162,
5161,
5160,
5159,
5159,
5158,
5157,
5156,
5156,
5155,
5154,
5153,
5152,
5152,
5151,
5150,
5149,
5149,
5148,
5147,
5146,
5146,
5145,
5144,
5143,
5143,
5142,
5141,
5140,
5140,
5139,
5138,
5137,
5137,
5136,
5135,
5135,
5134,
5133,
5132,
5132,
5131,
5130,
5129,
5129,
5128,
5127,
5127,
5126,
5125,
5125,
5124,
5123,
5122,
5122,
5121,
5120,
5120,
5119,
5118,
5118,
5117,
5116,
5116,
5115,
5114,
5114,
5113,
5112,
5112,
5111,
5110,
5110,
5109,
5108,
5108,
5107,
5106,
5106,
5105,
5105,
5104,
5103,
5103,
5102,
5101,
5101,
5100,
5099,
5099,
5098,
5098,
5097,
5096,
5096,
5095,
5095,
5094,
5093,
5093,
5092,
5092,
5091,
5090,
5090,
5089,
5089,
5088,
5087,
5087,
5086,
5086,
5085,
5084,
5084,
5083,
5083,
5082,
5082,
5081,
5081,
5080,
5079,
5079,
5078,
5078,
5077,
5077,
5076,
5076,
5075,
5074,
5074,
5073,
5073,
5072,
5072,
5071,
5071,
5070,
5070,
5069,
5069,
5068,
5068,
5067,
5067,
5066,
5066,
5065,
5065,
5064,
5064,
5063,
5063,
5062,
5062,
5061,
5061,
5060,
5060,
5059,
5059,
5058,
5058,
5057,
5057,
5056,
5056,
5055,
5055,
5054,
5054,
5053,
5053,
5053,
5052,
5052,
5051,
5051,
5050,
5050,
5049,
5049,
5049,
5048,
5048,
5047,
5047,
5046,
5046,
5046,
5045,
5045,
5044,
5044,
5043,
5043,
5043,
5042,
5042,
5041,
5041,
5041,
5040,
5040,
5039,
5039,
5039,
5038,
5038,
5037,
5037,
5037,
5036,
5036,
5036,
5035,
5035,
5034,
5034,
5034,
5033,
5033,
5033,
5032,
5032,
5032,
5031,
5031,
5031,
5030,
5030,
5030,
5029,
5029,
5028,
5028,
5028,
5028,
5027,
5027,
5027,
5026,
5026,
5026,
5025,
5025,
5025,
5024,
5024,
5024,
5023,
5023,
5023,
5022,
5022,
5022,
5022,
5021,
5021,
5021,
5020,
5020,
5020,
5020,
5019,
5019,
5019,
5019,
5018,
5018,
5018,
5017,
5017,
5017,
5017,
5016,
5016,
5016,
5016,
5015,
5015,
5015,
5015,
5014,
5014,
5014,
5014,
5014,
5013,
5013,
5013,
5013,
5012,
5012,
5012,
5012,
5012,
5011,
5011,
5011,
5011,
5010,
5010,
5010,
5010,
5010,
5009,
5009,
5009,
5009,
5009,
5009,
5008,
5008,
5008,
5008,
5008,
5007,
5007,
5007,
5007,
5007,
5007,
5006,
5006,
5006,
5006,
5006,
5006,
5006,
5005,
5005,
5005,
5005,
5005,
5005,
5005,
5004,
5004,
5004,
5004,
5004,
5004,
5004,
5004,
5003,
5003,
5003,
5003,
5003,
5003,
5003,
5003,
5003,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5002,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5001,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
5000,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4999,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4998,
4997,
4997,
4997,
4997,
4997,
4997,
4997,
4997,
4997,
4996,
4996,
4996,
4996,
4996,
4996,
4996,
4996,
4995,
4995,
4995,
4995,
4995,
4995,
4995,
4994,
4994,
4994,
4994,
4994,
4994,
4994,
4993,
4993,
4993,
4993,
4993,
4993,
4992,
4992,
4992,
4992,
4992,
4991,
4991,
4991,
4991,
4991,
4991,
4990,
4990,
4990,
4990,
4990,
4989,
4989,
4989,
4989,
4988,
4988,
4988,
4988,
4988,
4987,
4987,
4987,
4987,
4986,
4986,
4986,
4986,
4986,
4985,
4985,
4985,
4985,
4984,
4984,
4984,
4984,
4983,
4983,
4983,
4983,
4982,
4982,
4982,
4981,
4981,
4981,
4981,
4980,
4980,
4980,
4980,
4979,
4979,
4979,
4978,
4978,
4978,
4978,
4977,
4977,
4977,
4976,
4976,
4976,
4975,
4975,
4975,
4974,
4974,
4974,
4973,
4973,
4973,
4972,
4972,
4972,
4972,
4971,
4971,
4970,
4970,
4970,
4969,
4969,
4969,
4968,
4968,
4968,
4967,
4967,
4967,
4966,
4966,
4966,
4965,
4965,
4964,
4964,
4964,
4963,
4963,
4963,
4962,
4962,
4961,
4961,
4961,
4960,
4960,
4959,
4959,
4959,
4958,
4958,
4957,
4957,
4957,
4956,
4956,
4955,
4955,
4954,
4954,
4954,
4953,
4953,
4952,
4952,
4951,
4951,
4951,
4950,
4950,
4949,
4949,
4948,
4948,
4947,
4947,
4947,
4946,
4946,
4945,
4945,
4944,
4944,
4943,
4943,
4942,
4942,
4941,
4941,
4940,
4940,
4939,
4939,
4938,
4938,
4937,
4937,
4936,
4936,
4935,
4935,
4934,
4934,
4933,
4933,
4932,
4932,
4931,
4931,
4930,
4930,
4929,
4929,
4928,
4928,
4927,
4927,
4926,
4926,
4925,
4924,
4924,
4923,
4923,
4922,
4922,
4921,
4921,
4920,
4919,
4919,
4918,
4918,
4917,
4917,
4916,
4916,
4915,
4914,
4914,
4913,
4913,
4912,
4911,
4911,
4910,
4910,
4909,
4908,
4908,
4907,
4907,
4906,
4905,
4905,
4904,
4904,
4903,
4902,
4902,
4901,
4901,
4900,
4899,
4899,
4898,
4897,
4897,
4896,
4895,
4895,
4894,
4894,
4893,
4892,
4892,
4891,
4890,
4890,
4889,
4888,
4888,
4887,
4886,
4886,
4885,
4884,
4884,
4883,
4882,
4882,
4881,
4880,
4880,
4879,
4878,
4878,
4877,
4876,
4875,
4875,
4874,
4873,
4873,
4872,
4871,
4871,
4870,
4869,
4868,
4868,
4867,
4866,
4865,
4865,
4864,
4863,
4863,
4862,
4861,
4860,
4860,
4859,
4858,
4857,
4857,
4856,
4855,
4854,
4854,
4853,
4852,
4851,
4851,
4850,
4849,
4848,
4848,
4847,
4846,
4845,
4844,
4844,
4843,
4842,
4841,
4841,
4840,
4839,
4838,
4837,
4837,
4836,
4835,
4834,
4833,
4833,
4832,
4831,
4830,
4829,
4829,
4828,
4827,
4826,
4825,
4824,
4824,
4823,
4822,
4821,
4820,
4819,
4819,
4818,
4817,
4816,
4815,
4814,
4814,
4813,
4812,
4811,
4810,
4809,
4808,
4808,
4807,
4806,
4805,
4804,
4803,
4802,
4801,
4801,
4800,
4799,
4798,
4797,
4796,
4795,
4794,
4794,
4793,
4792,
4791,
4790,
4789,
4788,
4787,
4786,
4785,
4784,
4784,
4783,
4782,
4781,
4780,
4779,
4778,
4777,
4776,
4775,
4774,
4773,
4772,
4772,
4771,
4770,
4769,
4768,
4767,
4766,
4765,
4764,
4763,
4762,
4761,
4760,
4759,
4758,
4757,
4756,
4755,
4754,
4753,
4752,
4751,
4750,
4749,
4748,
4747,
4746,
4745,
4744,
4743,
4743,
4742,
4741,
4740,
4739,
4738,
4736,
4735,
4734,
4733,
4732,
4731,
4730,
4729,
4728,
4727,
4726,
4725,
4724,
4723,
4722,
4721,
4720,
4719,
4718,
4717,
4716,
4715,
4714,
4713,
4712,
4711,
4710,
4709,
4708,
4707,
4705,
4704,
4703,
4702,
4701,
4700,
4699,
4698,
4697,
4696,
4695,
4694,
4693,
4692,
4690,
4689,
4688,
4687,
4686,
4685,
4684,
4683,
4682,
4681,
4679,
4678,
4677,
4676,
4675,
4674,
4673,
4672,
4671,
4669,
4668,
4667,
4666,
4665,
4664,
4663,
4661,
4660,
4659,
4658,
4657,
4656,
4655,
4653,
4652,
4651,
4650,
4649,
4648,
4647,
4645,
4644,
4643,
4642,
4641,
4640,
4638,
4637,
4636,
4635,
4634,
4633,
4631,
4630,
4629,
4628,
4627,
4625,
4624,
4623,
4622,
4621,
4619,
4618,
4617,
4616,
4615,
4613,
4612,
4611,
4610,
4609,
4607,
4606,
4605,
4604,
4602,
4601,
4600,
4599,
4597,
4596,
4595,
4594,
4593,
4591,
4590,
4589,
4588,
4586,
4585,
4584,
4583,
4581,
4580,
4579,
4577,
4576,
4575,
4574,
4572,
4571,
4570,
4569,
4567,
4566,
4565,
4563,
4562,
4561,
4560,
4558,
4557,
4556,
4554,
4553,
4552,
4551,
4549,
4548,
4547,
4545,
4544,
4543,
4541,
4540,
4539,
4537,
4536,
4535,
4533,
4532,
4531,
4529,
4528,
4527,
4525,
4524,
4523,
4521,
4520,
4519,
4517,
4516,
4515,
4513,
4512,
4511,
4509,
4508,
4507,
4505,
4504,
4503,
4501,
4500,
4498,
4497,
4496,
4494,
4493,
4492,
4490,
4489,
4487,
4486,
4485,
4483,
4482,
4480,
4479,
4478,
4476,
4475,
4473,
4472,
4471,
4469,
4468,
4466,
4465,
4464,
4462,
4461,
4459,
4458,
4456,
4455,
4454,
4452,
4451,
4449,
4448,
4446,
4445,
4444,
4442,
4441,
4439,
4438,
4436,
4435,
4433,
4432,
4431,
4429,
4428,
4426,
4425,
4423,
4422,
4420,
4419,
4417,
4416,
4414,
4413,
4411,
4410,
4408,
4407,
4406,
4404,
4403,
4401,
4400,
4398,
4397,
4395,
4394,
4392,
4391,
4389,
4388,
4386,
4385,
4383,
4382,
4380,
4379,
4377,
4375,
4374,
4372,
4371,
4369,
4368,
4366,
4365,
4363,
4362,
4360,
4359,
4357,
4356,
4354,
4352,
4351,
4349,
4348,
4346,
4345,
4343,
4342,
4340,
4338,
4337,
4335,
4334,
4332,
4331,
4329,
4328,
4326,
4324,
4323,
4321,
4320,
4318,
4316,
4315,
4313,
4312,
4310,
4309,
4307,
4305,
4304,
4302,
4301,
4299,
4297,
4296,
4294,
4292,
4291,
4289,
4288,
4286,
4284,
4283,
4281,
4280,
4278,
4276,
4275,
4273,
4271,
4270,
4268,
4266,
4265,
4263,
4262,
4260,
4258,
4257,
4255,
4253,
4252,
4250,
4248,
4247,
4245,
4243,
4242,
4240,
4238,
4237,
4235,
4233,
4232,
4230,
4228,
4227,
4225,
4223,
4222,
4220,
4218,
4217,
4215,
4213,
4212,
4210,
4208,
4206,
4205,
4203,
4201,
4200,
4198,
4196,
4194,
4193,
4191,
4189,
4188,
4186,
4184,
4182,
4181,
4179,
4177,
4176,
4174,
4172,
4170,
4169,
4167,
4165,
4163,
4162,
4160,
4158,
4156,
4155,
4153,
4151,
4149,
4148,
4146,
4144,
4142,
4141,
4139,
4137,
4135,
4134,
4132,
4130,
4128,
4127,
4125,
4123,
4121,
4119,
4118,
4116,
4114,
4112,
4111,
4109,
4107,
4105,
4103,
4102,
4100,
4098,
4096,
4094,
4093,
4091,
4089,
4087,
4085,
4084,
4082,
4080,
4078,
4076,
4074,
4073,
4071,
4069,
4067,
4065,
4063,
4062,
4060,
4058,
4056,
4054,
4052,
4051,
4049,
4047,
4045,
4043,
4041,
4040,
4038,
4036,
4034,
4032,
4030,
4028,
4027,
4025,
4023,
4021,
4019,
4017,
4015,
4013,
4012,
4010,
4008,
4006,
4004,
4002,
4000,
3998,
3997,
3995,
3993,
3991,
3989,
3987,
3985,
3983,
3981,
3979,
3978,
3976,
3974,
3972,
3970,
3968,
3966,
3964,
3962,
3960,
3958,
3957,
3955,
3953,
3951,
3949,
3947,
3945,
3943,
3941,
3939,
3937,
3935,
3933,
3931,
3930,
3928,
3926,
3924,
3922,
3920,
3918,
3916,
3914,
3912,
3910,
3908,
3906,
3904,
3902,
3900,
3898,
3896,
3894,
3892,
3890,
3888,
3886,
3884,
3882,
3880,
3878,
3876,
3875,
3873,
3871,
3869,
3867,
3865,
3863,
3861,
3859,
3857,
3855,
3853,
3851,
3849,
3847,
3845,
3843,
3841,
3839,
3836,
3834,
3832,
3830,
3828,
3826,
3824,
3822,
3820,
3818,
3816,
3814,
3812,
3810,
3808,
3806,
3804,
3802,
3800,
3798,
3796,
3794,
3792,
3790,
3788,
3786,
3784,
3782,
3779,
3777,
3775,
3773,
3771,
3769,
3767,
3765,
3763,
3761,
3759,
3757,
3755,
3753,
3751,
3748,
3746,
3744,
3742,
3740,
3738,
3736,
3734,
3732,
3730,
3728,
3726,
3723,
3721,
3719,
3717,
3715,
3713,
3711,
3709,
3707,
3704,
3702,
3000,///////////// FROM ME
201///////////     FROM ME
/*
3700,
3698,
3696,
3694,
3692,
3690,
3688,
3685,
3683,
3681,
3679,
3677,
3675,
3673,
3671,
3668,
3666,
3664,
3662,
3660,
3658,
3656,
3653,
3651,
3649,
3647,
3645,
3643,
3641,
3638,
3636,
3634,
3632,
3630,
3628,
3625,
3623,
3621,
3619,
3617,
3615,
3612,
3610,
3608,
3606,
3604,
3602,
3599,
3597,
3595,
3593,
3591,
3588,
3586,
3584,
3582,
3580,
3577,
3575,
3573,
3571,
3569,
3566,
3564,
3562,
3560,
3558,
3555,
3553,
3551,
3549,
3547,
3544,
3542,
3540,
3538,
3536,
3533,
3531,
3529,
3527,
3524,
3522,
3520,
3518,
3515,
3513,
3511,
3509,
3507,
3504,
3502,
3500,
3498,
3495,
3493,
3491,
3489,
3486,
3484,
3482,
3480,
3477,
3475,
3473,
3471,
3468,
3466,
3464,
3461,
3459,
3457,
3455,
3452,
3450,
3448,
3446,
3443,
3441,
3439,
3436,
3434,
3432,
3430,
3427,
3425,
3423,
3420,
3418,
3416,
3414,
3411,
3409,
3407,
3404,
3402,
3400,
3397,
3395,
3393,
3391,
3388,
3386,
3384,
3381,
3379,
3377,
3374,
3372,
3370,
3367,
3365,
3363,
3360,
3358,
3356,
3353,
3351,
3349,
3346,
3344,
3342,
3339,
3337,
3335,
3332,
3330,
3328,
3325,
3323,
3321,
3318,
3316,
3314,
3311,
3309,
3307,
3304,
3302,
3299,
3297,
3295,
3292,
3290,
3288,
3285,
3283,
3281,
3278,
3276,
3273,
3271,
3269,
3266,
3264,
3262,
3259,
3257,
3254,
3252,
3250,
3247,
3245,
3242,
3240,
3238,
3235,
3233,
3230,
3228,
3226,
3223,
3221,
3218,
3216,
3214,
3211,
3209,
3206,
3204,
3202,
3199,
3197,
3194,
3192,
3190,
3187,
3185,
3182,
3180,
3177,
3175,
3173,
3170,
3168,
3165,
3163,
3160,
3158,
3156,
3153,
3151,
3148,
3146,
3143,
3141,
3138,
3136,
3134,
3131,
3129,
3126,
3124,
3121,
3119,
3116,
3114,
3111,
3109,
3107,
3104,
3102,
3099,
3097,
3094,
3092,
3089,
3087,
3084,
3082,
3079,
3077,
3074,
3072,
3069,
3067,
3065,
3062,
3060,
3057,
3055,
3052,
3050,
3047,
3045,
3042,
3040,
3037,
3035,
3032,
3030,
3027,
3025,
3022,
3020,
3017,
3015,
3012,
3010,
3007,
3005,
3002,
3000,
2997,
2995,
2992,
2990,
2987,
2984,
2982,
2979,
2977,
2974,
2972,
2969,
2967,
2964,
2962,
2959,
2957,
2954,
2952,
2949,
2947,
2944,
2941,
2939,
2936,
2934,
2931,
2929,
2926,
2924,
2921,
2919,
2916,
2913,
2911,
2908,
2906,
2903,
2901,
2898,
2896,
2893,
2890,
2888,
2885,
2883,
2880,
2878,
2875,
2872,
2870,
2867,
2865,
2862,
2860,
2857,
2854,
2852,
2849,
2847,
2844,
2842,
2839,
2836,
2834,
2831,
2829,
2826,
2823,
2821,
2818,
2816,
2813,
2810,
2808,
2805,
2803,
2800,
2797,
2795,
2792,
2790,
2787,
2784,
2782,
2779,
2777,
2774,
2771,
2769,
2766,
2763,
2761,
2758,
2756,
2753,
2750,
2748,
2745,
2742,
2740,
2737,
2735,
2732,
2729,
2727,
2724,
2721,
2719,
2716,
2714,
2711,
2708,
2706,
2703,
2700,
2698,
2695,
2692,
2690,
2687,
2684,
2682,
2679,
2676,
2674,
2671,
2669,
2666,
2663,
2661,
2658,
2655,
2653,
2650,
2647,
2645,
2642,
2639,
2637,
2634,
2631,
2629,
2626,
2623,
2621,
2618,
2615,
2612,
2610,
2607,
2604,
2602,
2599,
2596,
2594,
2591,
2588,
2586,
2583,
2580,
2578,
2575,
2572,
2570,
2567,
2564,
2561,
2559,
2556,
2553,
2551,
2548,
2545,
2543,
2540,
2537,
2534,
2532,
2529,
2526,
2524,
2521,
2518,
2515,
2513,
2510,
2507,
2505,
2502,
2499,
2496,
2494,
2491,
2488,
2485,
2483,
2480,
2477,
2475,
2472,
2469,
2466,
2464,
2461,
2458,
2455,
2453,
2450,
2447,
2444,
2442,
2439,
2436,
2434,
2431,
2428,
2425,
2423,
2420,
2417,
2414,
2412,
2409,
2406,
2403,
2401,
2398,
2395,
2392,
2389,
2387,
2384,
2381,
2378,
2376,
2373,
2370,
2367,
2365,
2362,
2359,
2356,
2354,
2351,
2348,
2345,
2342,
2340,
2337,
2334,
2331,
2329,
2326,
2323,
2320,
2317,
2315,
2312,
2309,
2306,
2303,
2301,
2298,
2295,
2292,
2290,
2287,
2284,
2281,
2278,
2276,
2273,
2270,
2267,
2264,
2262,
2259,
2256,
2253,
2250,
2248,
2245,
2242,
2239,
2236,
2233,
2231,
2228,
2225,
2222,
2219,
2217,
2214,
2211,
2208,
2205,
2203,
2200,
2197,
2194,
2191,
2188,
2186,
2183,
2180,
2177,
2174,
2171,
2169,
2166,
2163,
2160,
2157,
2154,
2152,
2149,
2146,
2143,
2140,
2137,
2135,
2132,
2129,
2126,
2123,
2120,
2118,
2115,
2112,
2109,
2106,
2103,
2100,
2098,
2095,
2092,
2089,
2086,
2083,
2080,
2078,
2075,
2072,
2069,
2066,
2063,
2060,
2058,
2055,
2052,
2049,
2046,
2043,
2040,
2038,
2035,
2032,
2029,
2026,
2023,
2020,
2017,
2015,
2012,
2009,
2006,
2003,
2000,
1997,
1994,
1992,
1989,
1986,
1983,
1980,
1977,
1974,
1971,
1968,
1966,
1963,
1960,
1957,
1954,
1951,
1948,
1945,
1942,
1940,
1937,
1934,
1931,
1928,
1925,
1922,
1919,
1916,
1913,
1911,
1908,
1905,
1902,
1899,
1896,
1893,
1890,
1887,
1884,
1881,
1879,
1876,
1873,
1870,
1867,
1864,
1861,
1858,
1855,
1852,
1849,
1846,
1844,
1841,
1838,
1835,
1832,
1829,
1826,
1823,
1820,
1817,
1814,
1811,
1808,
1806,
1803,
1800,
1797,
1794,
1791,
1788,
1785,
1782,
1779,
1776,
1773,
1770,
1767,
1764,
1761,
1759,
1756,
1753,
1750,
1747,
1744,
1741,
1738,
1735,
1732,
1729,
1726,
1723,
1720,
1717,
1714,
1711,
1708,
1706,
1703,
1700,
1697,
1694,
1691,
1688,
1685,
1682,
1679,
1676,
1673,
1670,
1667,
1664,
1661,
1658,
1655,
1652,
1649,
1646,
1643,
1640,
1637,
1634,
1631,
1629,
1626,
1623,
1620,
1617,
1614,
1611,
1608,
1605,
1602,
1599,
1596,
1593,
1590,
1587,
1584,
1581,
1578,
1575,
1572,
1569,
1566,
1563,
1560,
1557,
1554,
1551,
1548,
1545,
1542,
1539,
1536,
1533,
1530,
1527,
1524,
1521,
1518,
1515,
1512,
1509,
1506,
1503,
1500,
1497,
1494,
1491,
1488,
1485,
1482,
1479,
1476,
1473,
1470,
1467,
1464,
1461,
1458,
1455,
1452,
1449,
1446,
1443,
1440,
1437,
1434,
1431,
1428,
1425,
1422,
1419,
1416,
1413,
1410,
1407,
1404,
1401,
1398,
1395,
1392,
1389,
1386,
1383,
1380,
1377,
1374,
1371,
1368,
1365,
1362,
1359,
1356,
1353,
1350,
1347,
1344,
1341,
1338,
1335,
1331,
1328,
1325,
1322,
1319,
1316,
1313,
1310,
1307,
1304,
1301,
1298,
1295,
1292,
1289,
1286,
1283,
1280,
1277,
1274,
1271,
1268,
1265,
1262,
1259,
1256,
1253,
1250,
1246,
1243,
1240,
1237,
1234,
1231,
1228,
1225,
1222,
1219,
1216,
1213,
1210,
1207,
1204,
1201,
1198,
1195,
1192,
1189,
1186,
1182,
1179,
1176,
1173,
1170,
1167,
1164,
1161,
1158,
1155,
1152,
1149,
1146,
1143,
1140,
1137,
1134,
1131,
1127,
1124,
1121,
1118,
1115,
1112,
1109,
1106,
1103,
1100,
1097,
1094,
1091,
1088,
1085,
1082,
1078,
1075,
1072,
1069,
1066,
1063,
1060,
1057,
1054,
1051,
1048,
1045,
1042,
1039,
1035,
1032,
1029,
1026,
1023,
1020,
1017,
1014,
1011,
1008,
1005,
1002,
999,
995,
992,
989,
986,
983,
980,
977,
974,
971,
968,
965,
962,
958,
955,
952,
949,
946,
943,
940,
937,
934,
931,
928,
925,
921,
918,
915,
912,
909,
906,
903,
900,
897,
894,
891,
887,
884,
881,
878,
875,
872,
869,
866,
863,
860,
857,
853,
850,
847,
844,
841,
838,
835,
832,
829,
826,
822,
819,
816,
813,
810,
807,
804,
801,
798,
795,
791,
788,
785,
782,
779,
776,
773,
770,
767,
764,
760,
757,
754,
751,
748,
745,
742,
739,
736,
732,
729,
726,
723,
720,
717,
714,
711,
708,
705,
701,
698,
695,
692,
689,
686,
683,
680,
677,
673,
670,
667,
664,
661,
658,
655,
652,
648,
645,
642,
639,
636,
633,
630,
627,
624,
620,
617,
614,
611,
608,
605,
602,
599,
595,
592,
589,
586,
583,
580,
577,
574,
571,
567,
564,
561,
558,
555,
552,
549,
546,
542,
539,
536,
533,
530,
527,
524,
521,
517,
514,
511,
508,
505,
502,
499,
496,
492,
489,
486,
483,
480,
477,
474,
471,
467,
464,
461,
458,
455,
452,
449,
446,
442,
439,
436,
433,
430,
427,
424,
420,
417,
414,
411,
408,
405,
402,
399,
395,
392,
389,
386,
383,
380,
377,
374,
370,
367,
364,
361,
358,
355,
352,
348,
345,
342,
339,
336,
333,
330,
326,
323,
320,
317,
314,
311,
308,
305,
301,
298,
295,
292,
289,
286,
283,
279,
276,
273,
270,
267,
264,
261,
257,
254,
251,
248,
245,
242,
239,
236,
232,
229,
226,
223,
220,
217,
214,
210,
207,
204,
201,
198,
195,
192,
188,
185,
182,
179,
176,
173,
170,
166,
163,
160,
157,
154,
151,
148,
144,
141,
138,
135,
132,
129,
126,
123,
119,
116,
113,
110,
107,
104,
101,
97,
94,
91,
88,
85,
82,
79,
75,
72,
69,
66,
63,
60,
57,
53,
50,
47,
44,
41,
38,
35,
31,
28,
25,
22,
19,
16,
13,
9,
6,
3,
0,

	*/
	};

#endif