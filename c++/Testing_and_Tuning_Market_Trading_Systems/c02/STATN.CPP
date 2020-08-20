if (version == 0)
 full_lookback = lookback ;
 else if (version == 1)
 full_lookback = 2 * lookback ;
 else if (version > 1)
 full_lookback = version * lookback ;
 nind = nprices - full_lookback + 1 ; // This many indicators
