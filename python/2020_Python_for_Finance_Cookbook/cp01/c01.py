import pandas as pd
import numpy as np
import yfinance as yf
df = yf.download('AAPL', start='2000-01-01', end='2010-12-31', progress=False)
df = df.loc[:, ['Adj Close']]
df.rename(columns={'Adj Close':'adj_close'}, inplace=True)
df['simple_rtn'] = df.adj_close.pct_change()
df['log_rtn'] = np.log(df.adj_close/df.adj_close.shift(1))
