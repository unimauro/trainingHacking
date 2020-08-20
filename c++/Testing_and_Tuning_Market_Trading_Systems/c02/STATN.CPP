if (version == 0)
 full_lookback = lookback ;
 else if (version == 1)
 full_lookback = 2 * lookback ;
 else if (version > 1)
 full_lookback = version * lookback ;
 nind = nprices - full_lookback + 1 ; // This many indicators


//

for (i=0 ; i<nind ; i++) {
 k = full_lookback - 1 + i ;
 if (version == 0)
 trend[i] = find_slope ( lookback , close + k ) ;
 else if (version == 1)
 trend[i] = find_slope ( lookback , close + k ) –
 find_slope ( lookback , close + k - lookback ) ;
 else
 trend[i] = find_slope ( lookback , close + k ) –
 find_slope ( full_lookback , close + k ) ;
 trend_sorted[i] = trend[i] ;
 }

//


qsortd ( 0 , nind-1 , trend_sorted ) ;
 k = (int) (fractile * (nind+1)) - 1 ;
 if (k < 0)
 k = 0 ;
 trend_quantile = trend_sorted[k] ;
 gap_analyze ( nind , trend , trend_quantile , ngaps , gap_size , gap_count ) ;


//
