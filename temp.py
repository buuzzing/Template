from selenium import webdriver
from selenium.webdriver.support.wait import WebDriverWait as wait
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support import expected_conditions   as ec
from selenium.common.exceptions import TimeoutException
from selenium.common.exceptions import SessionNotCreatedException
from selenium.webdriver.support.select import Select
import sys
import os
import requests
import time
import re

USERNAME = '201924100448'
PASSWORD = '01110010'

wd = webdriver.Chrome(r"C:\Users\Administrator\Downloads\chromedriver.exe")

wd.get(r"http://jksb.zzu.edu.cn/")
wd.switch_to.frame(0)
wd.implicitly_wait(3)

username = wd.find_element_by_name('uid')
username.send_keys(USERNAME)
time.sleep(1)
password = wd.find_element_by_name('upw')
password.send_keys(PASSWORD)

login_button = wd.find_element_by_xpath("//div[@class='mt_3e']/input")
login_button.submit()

wd.switch_to.frame('zzj_top_6s')
time.sleep(1)
login_button = wd.find_element_by_xpath("//[@style='width:80px;height:100%;float:left;line-height:32px;font-family:黑体;background-image:url(/images/btn/greenq80.png);text-align:center;'")
login_button.submit()

time.sleep(5)

wd.quit()
