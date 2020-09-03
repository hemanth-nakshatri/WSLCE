#!/usr/bin/env python
# coding: utf-8

# In[3]:


import numpy as np
import matplotlib.pyplot as plt
import random
import math
from matplotlib.pyplot import step, xlim, ylim, show, plot


#############################
# Define WSLCE function
#############################


def WSLCE(p, k=1):
    global ut
    global w_k
    
    # Add your pr_list path in the line below
    
    pr = np.loadtxt('E:\Downloads\WSLCE\pr_list\pr_{}.txt'.format(p)) 
    x=int(random.choice(pr))
    print("Primtive Element is " + str(x))
    k = (p-1)//2
    s=[]
    
    for i in range(0,k):
        s.append(x**((2*i)+1)%p)

        ut = []
    for t in range(0,p):
        if (((x**t)+1)%p) in s:
            ut.append(1)
        else:
            ut.append(0)

    ut = ut[-1:]+ut[:-1]
    print("SLCE sequence is ")
    print(ut)

    
    ut_k=ut[-k:]+ut[:-k]

    w_k=np.zeros(len(ut))

    for i in range(0,len(ut)):
        w_k[i]=ut[i]^ut_k[i]


    print("WSLCE sequence is ")
    print(w_k)
    
#######################################################
# Call WSLCE function with Prime 'p' and shift 'k'
#######################################################

p = 13
WSLCE(p, k=3)



