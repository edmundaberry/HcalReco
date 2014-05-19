#include "fitResults.h"

Double_t fitResults::a0_HB (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-19.8632481927, 13.9294296945, -0.39400460012, 0.0880287729034};
  float exp[3] = {16.765808875, -0.796304171443, -3.66608236901};
  float pol11[2] = {-0.0597940318636, 3.4734865038e-06};
  float pol12[2] = {0.0276688133939, 8.4014619742e-06};
  float limits[1] = {114.83978548};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_1720 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-13.4470760503, 12.6425388494, -0.390503512534, 0.0435038145577};
  float exp[3] = {16.6533949428, -0.643410365726, -4.7140073969};
  float pol11[2] = {-0.00758507988479, 0.000134792985636};
  float pol12[2] = {0.0415836539494, 2.70407097328e-06};
  float limits[1] = {42.9008205599};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_2123 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-22.9549437453, 17.7280605668, -0.448887414455, 0.0500392701903};
  float exp[3] = {25.4639144831, -0.825604615915, -3.30471611047};
  float pol11[2] = {-0.0119983498036, 4.60983354389e-05};
  float pol12[2] = {0.0415642200371, 6.36601171968e-07};
  float limits[1] = {77.5004153224};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_2425 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-22.3647037421, 17.8088078839, -0.3833591733, 0.041307040559};
  float exp[3] = {21.037987629, -0.797918185671, -3.4368418281};
  float pol11[2] = {-0.00276522973847, 4.13794661773e-05};
  float pol12[2] = {0.0421693815578, 1.14266519308e-06};
  float limits[1] = {90.1555467817};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_2627 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-24.8453239341, 16.872712109, -0.673688042582, 0.04165818839};
  float exp[3] = {23.3009277846, -0.749722630157, -3.95982680336};
  float pol11[2] = {-0.00175850045966, 5.86413732374e-05};
  float pol12[2] = {0.0441216053187, -1.05088150375e-06};
  float limits[1] = {70.7281486417};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_28 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-19.9255682249, 15.0471188926, -0.639467420294, 0.0205953961486};
  float exp[3] = {2.10899083173, -0.68115425432, -1.16326951569};
  float pol11[2] = {0.0187417522166, 7.70258515367e-05};
  float pol12[2] = {0.0440860991795, -2.66667990747e-06};
  float limits[1] = {59.5914362439};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a1_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.90259718677, -0.219984572791, 0.00669517265963, 0.000774294442323, -3.99989263738e-05};
  Double_t pol42[5] = {0.788122514892, -0.00655807765168, 2.95013620065e-05, 3.37708025013e-07, 2.15223689427e-10};
  Double_t pol31[4] = {0.690843076147, -0.00272296252994, 1.15209840775e-05, -1.68282749749e-08};
  Double_t pol32[4] = {0.687169994148, -0.00191288443777, 4.09933820933e-06, -2.19386851445e-09};
  Double_t pol11[2] = {0.478749600814, -0.000185796496818};
  Double_t pol12[2] = {0.351672445087, -3.462102699e-05};
  Double_t limits[5] = {15.0000232603, 35.4966121904, 150.565703418, 300.000000015, 840.593754213};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.82114130307, -0.199888181811, 0.00481756795952, 0.000714499970454, -3.26467105076e-05};
  Double_t pol42[5] = {0.968015165162, -0.0312122483145, 0.000811749246396, -4.73882827605e-06, -7.0678981487e-08};
  Double_t pol31[4] = {0.62763729954, -0.00229287873475, 7.98963791638e-06, -5.16016045196e-09};
  Double_t pol32[4] = {0.639733937273, -0.00191892542643, 4.71833844032e-06, -3.55583326894e-09};
  Double_t pol11[2] = {0.431686173757, -0.000122611275674};
  Double_t pol12[2] = {0.269269848063, 0.0};
  Double_t limits[5] = {15.4158158381, 36.4991486977, 150.000000025, 321.00060851, 1324.64428578};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.88749169807, -0.21976746665, 0.00568937042103, 0.000814232063483, -3.86845700784e-05};
  Double_t pol42[5] = {0.85914091155, -0.0180128976728, 0.000339503720813, -1.07155233646e-06, -2.38969233682e-08};
  Double_t pol31[4] = {0.643236738488, -0.0027530832803, 1.28754005676e-05, -2.34350518588e-08};
  Double_t pol32[4] = {0.949075358667, -0.00577406683067, 2.03577512592e-05, -2.44351824716e-08};
  Double_t pol11[2] = {0.439333271107, -0.000166730971766};
  Double_t pol12[2] = {0.286683285218, 0.0};
  Double_t limits[5] = {15.0157885955, 39.4755044272, 176.985287984, 301.503974408, 915.546669417};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.80796267589, -0.198151605916, 0.00477264709576, 0.000712384486216, -3.26276629691e-05};
  Double_t pol42[5] = {0.89200519536, -0.0227857617016, 0.000531012612482, -2.72515797743e-06, -4.30751191905e-08};
  Double_t pol31[4] = {0.628613394542, -0.00217054314272, 6.5889081019e-06, -1.26114956236e-09};
  Double_t pol32[4] = {0.774433286431, -0.00369694127224, 1.22940116814e-05, -1.42382825335e-08};
  Double_t pol11[2] = {0.444654515268, -0.00019027758629};
  Double_t pol12[2] = {0.292208035824, 0.0};
  Double_t limits[5] = {15.4264533047, 36.9190995823, 152.064913769, 310.49991592, 801.179384373};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.91081017554, -0.230222532624, 0.0070691869103, 0.00076007726394, -3.89728314252e-05};
  Double_t pol42[5] = {0.672935724554, 0.000373193277047, -0.000207416419594, 2.16712937731e-06, 2.20210956293e-08};
  Double_t pol31[4] = {0.620075666829, -0.00196497501831, 4.56183690616e-06, 4.29170040693e-09};
  Double_t pol32[4] = {0.629469975991, -0.00183910202432, 4.47950682966e-06, -3.53728671426e-09};
  Double_t pol11[2] = {0.455486885171, -0.000216652666189};
  Double_t pol12[2] = {0.305144081091, 0.0};
  Double_t limits[5] = {15.0002434268, 37.0654141353, 150.000000014, 333.985953133, 693.934705372};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_28 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.89777870386, -0.226211286132, 0.00625902304994, 0.000833364416408, -4.12566675114e-05};
  Double_t pol42[5] = {0.686372586996, -0.00205205756597, -0.000106191507864, 1.35705939938e-06, 1.17900099798e-08};
  Double_t pol31[4] = {0.624434941587, -0.00204842586747, 5.00921489653e-06, 4.99337776012e-09};
  Double_t pol32[4] = {0.636923870124, -0.00177067014669, 3.60721261286e-06, -1.59931515887e-09};
  Double_t pol11[2] = {0.438846389394, -0.000172186458028};
  Double_t pol12[2] = {0.2974356791, 0.0};
  Double_t limits[5] = {15.0000045878, 38.0192573881, 150.604402927, 300.000000003, 821.264993271};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.560910995302, -0.063240501265, 0.0017801388413, 0.000213347606063, -1.0428805319e-05};
  Double_t pol42[5] = {0.235656334872, -0.00254333016866, 1.91182752201e-05, 1.34770157792e-07, 3.9048770349e-11};
  Double_t pol31[4] = {0.198953212505, -0.000768026944345, 3.17707817536e-06, -5.1568192621e-09};
  Double_t pol32[4] = {0.193504414659, -0.000508466224835, 9.88058715382e-07, -4.72909073459e-10};
  Double_t pol11[2] = {0.135071800164, -5.98350451798e-05};
  Double_t pol12[2] = {0.0935245895544, -9.30692598952e-06};
  Double_t limits[5] = {15.4417093705, 37.1725737779, 150.500725364, 300.000000009, 822.259194978};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.497161437928, -0.0558160711917, 0.0014357927989, 0.000180590723838, -8.4078880111e-06};
  Double_t pol42[5] = {0.20572510442, -0.00365670550357, 6.185747114e-05, -1.62840698951e-07, -4.71470396891e-09};
  Double_t pol31[4] = {0.156210436706, -0.000603360974838, 2.66028717682e-06, -3.94802005621e-09};
  Double_t pol32[4] = {0.160886786045, -0.00049702583298, 1.31153501758e-06, -1.06793014704e-09};
  Double_t pol11[2] = {0.1099501149, -2.69013627586e-05};
  Double_t pol12[2] = {0.0708776813051, 0.0};
  Double_t limits[5] = {15.7251518527, 39.5001691348, 150.000004606, 324.610989179, 1452.43324456};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.461664066603, -0.047421097489, 0.00108257901179, 0.000145628167155, -6.2465266596e-06};
  Double_t pol42[5] = {0.280350054924, -0.0115690519845, 0.000319726116534, -1.96173007459e-06, -2.88230728165e-08};
  Double_t pol31[4] = {0.160700686297, -0.000723621924448, 3.64899118963e-06, -7.38452454138e-09};
  Double_t pol32[4] = {0.0991129803364, 2.07406975226e-05, -3.14894776634e-08, -2.09281899738e-10};
  Double_t pol11[2] = {0.10636840525, -3.32099692199e-05};
  Double_t pol12[2] = {0.0739901015311, 0.0};
  Double_t limits[5] = {16.1088267188, 35.2397862719, 217.324856877, 317.544380806, 974.957354054};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.503724856677, -0.0578122345677, 0.00146790390134, 0.000198390742624, -9.22263685655e-06};
  Double_t pol42[5] = {0.250067374212, -0.00816939262462, 0.000204843854941, -1.1273498244e-06, -1.70573665989e-08};
  Double_t pol31[4] = {0.160242011154, -0.000665458961762, 2.83998354249e-06, -4.11756102253e-09};
  Double_t pol32[4] = {0.208091334333, -0.00114942975579, 4.1072140024e-06, -5.06509559111e-09};
  Double_t pol11[2] = {0.108550593756, -4.29904732325e-05};
  Double_t pol12[2] = {0.0751987879121, 0.0};
  Double_t limits[5] = {15.2750158094, 36.7703469832, 153.447880265, 322.406500361, 775.795271271};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.491384373715, -0.0563528632854, 0.0014612668677, 0.000192893850474, -9.08013851502e-06};
  Double_t pol42[5] = {0.234219819605, -0.00618553879676, 9.34609023532e-05, 1.76523645683e-06, -4.60104839751e-08};
  Double_t pol31[4] = {0.155332071789, -0.000576553862025, 2.03865148048e-06, -1.82328874957e-09};
  Double_t pol32[4] = {0.138227919038, -0.000209981719549, -6.41518442577e-08, 9.71201972284e-10};
  Double_t pol11[2] = {0.109909234981, -4.74234817541e-05};
  Double_t pol12[2] = {0.076806542729, 0.0};
  Double_t limits[5] = {15.0533063369, 36.7613181539, 150.0, 300.000000206, 698.023237165};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_28 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.495269868936, -0.0567619226064, 0.00140250850166, 0.00019451844155, -8.90979657878e-06};
  Double_t pol42[5] = {0.25525692352, -0.00960824782964, 0.000266826308876, -1.73315980942e-06, -2.23916772675e-08};
  Double_t pol31[4] = {0.154614420785, -0.000579115788036, 2.20326685614e-06, -2.44813412196e-09};
  Double_t pol32[4] = {0.156265246805, -0.000453173066411, 1.01852310024e-06, -6.20680456637e-10};
  Double_t pol11[2] = {0.106796219662, -3.8580620286e-05};
  Double_t pol12[2] = {0.0751061662646, 0.0};
  Double_t limits[5] = {15.4311186288, 36.2075662631, 150.500017524, 300.000000066, 821.398234711};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.207464900942, -0.0248872709394, 0.000734303567505, 8.39688352536e-05, -4.133410131e-06};
  Double_t pol42[5] = {0.100680375582, -0.00282611522054, 7.5600030646e-05, -4.09789486759e-07, -8.00717142249e-09};
  Double_t pol31[4] = {0.0725266820519, -0.000250585007615, 8.91973903757e-07, -1.35231074635e-09};
  Double_t pol32[4] = {0.0718478272127, -0.000198428550867, 4.17692168069e-07, -3.04480747206e-10};
  Double_t pol11[2] = {0.0492357528298, -2.51505864226e-05};
  Double_t pol12[2] = {0.0314416724256, -3.37467643583e-06};
  Double_t limits[5] = {15.0046222781, 35.000000226, 150.500027784, 300.000000262, 817.145203803};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.167981225345, -0.0196803934275, 0.000489091856015, 6.43032097509e-05, -2.89344722435e-06};
  Double_t pol42[5] = {0.0908187334082, -0.00407656180202, 0.000116898849875, -6.63507281583e-07, -1.27840149664e-08};
  Double_t pol31[4] = {0.049202205349, -0.000183375440725, 7.92515988271e-07, -1.0874106573e-09};
  Double_t pol32[4] = {0.0500222513797, -0.00014774675548, 4.03854083968e-07, -3.22805009584e-10};
  Double_t pol11[2] = {0.0362431893977, -8.39589194333e-06};
  Double_t pol12[2] = {0.0236493514841, 0.0};
  Double_t limits[5] = {16.0915665887, 35.0, 150.00000108, 321.800890367, 1499.99999984};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.172794042818, -0.0207263117939, 0.000540737161916, 6.87751446594e-05, -3.19146839027e-06};
  Double_t pol42[5] = {0.0685114263858, -0.00117376362102, 1.18229477014e-05, 6.96004205422e-08, -1.08336084465e-10};
  Double_t pol31[4] = {0.0543861903876, -0.000352792985702, 2.43307483769e-06, -6.63779764341e-09};
  Double_t pol32[4] = {0.0324945784141, 7.18503849025e-05, -5.76547626581e-07, 1.0397169717e-09};
  Double_t pol11[2] = {0.0332169887661, -9.86139743921e-06};
  Double_t pol12[2] = {0.023772281954, 0.0};
  Double_t limits[5] = {15.4422430741, 35.0000021642, 150.000000073, 301.513180066, 957.745275999};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.167876624067, -0.0193819001422, 0.000475859265783, 6.41316290457e-05, -2.88755254598e-06};
  Double_t pol42[5] = {0.067964049153, -0.00110312367495, 1.05705594709e-05, 6.73330979912e-08, -1.28709429516e-11};
  Double_t pol31[4] = {0.0538297300398, -0.000303836488216, 1.75316067429e-06, -4.00761878145e-09};
  Double_t pol32[4] = {0.0519081103018, -0.000172522884631, 4.11653301666e-07, -2.72098900524e-10};
  Double_t pol11[2] = {0.0338512963245, -1.3326415198e-05};
  Double_t pol12[2] = {0.0237184785896, 0.0};
  Double_t limits[5] = {15.8002632657, 35.0000015905, 165.498894975, 300.000001174, 760.355848468};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.168642190774, -0.019839023498, 0.000492767506612, 6.54994034568e-05, -2.95381683346e-06};
  Double_t pol42[5] = {0.0659048706623, -0.0010166826375, 9.14086919313e-06, 5.83392409413e-08, -2.29367190898e-11};
  Double_t pol31[4] = {0.051738190511, -0.000263889901104, 1.29514587503e-06, -2.40650277586e-09};
  Double_t pol32[4] = {0.0364730547288, 2.11974852128e-05, -4.13307528454e-07, 8.82468304239e-10};
  Double_t pol11[2] = {0.0337445973394, -1.42777679153e-05};
  Double_t pol12[2] = {0.0239563341727, 0.0};
  Double_t limits[5] = {15.8956149598, 35.0000133762, 168.499989422, 300.000000719, 685.559761494};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_28 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.162799732235, -0.0193512146366, 0.000496698639558, 6.42632071385e-05, -2.97950021985e-06};
  Double_t pol42[5] = {0.0595923783957, -0.000744940019909, 6.04453687075e-06, 4.03328646299e-08, 5.07723319876e-12};
  Double_t pol31[4] = {0.0496061264149, -0.000236387757487, 1.15305939042e-06, -2.01970574685e-09};
  Double_t pol32[4] = {0.0531962560811, -0.000218556551797, 6.84774975256e-07, -7.48598844228e-10};
  Double_t pol11[2] = {0.0323253840879, -1.09283818635e-05};
  Double_t pol12[2] = {0.0232692107351, 0.0};
  Double_t limits[5] = {15.4084394765, 35.5110682478, 150.499887363, 300.000007127, 828.683831318};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

