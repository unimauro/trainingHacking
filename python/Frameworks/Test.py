from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait 
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options
import time

options = webdriver.ChromeOptions() 
options.add_argument("start-maximized")
options.add_argument('disable-infobars')

PATH = "C:\Program Files\chromedriver.exe"

driver = webdriver.Chrome(PATH, chrome_options=options)

driver.get("https://bonouniversalfamiliar.pe/#!/")
print(driver.title)

numeroDocumento = driver.find_element_by_name("numeroDocumento")
#search.send_keys("42226048")
#search.send_keys(Keys.RETURN)

numeroDocumento.send_keys("42226048")

date = driver.find_element_by_id("date")

date.send_keys("15042019")

time.sleep(25)

#che = driver.find_element_by_id("recaptcha-anchor")

#che.click()
WebDriverWait(driver, 10).until(EC.frame_to_be_available_and_switch_to_it((By.CSS_SELECTOR,"iframe[name^='a-'][src^='https://www.google.com/recaptcha/api2/anchor?']")))
WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.XPATH, "//span[@class='recaptcha-checkbox goog-inline-block recaptcha-checkbox-unchecked rc-anchor-checkbox']/div[@class='recaptcha-checkbox-checkmark']"))).click()



print(driver.page_source)

time.sleep(25)
driver.quit()

