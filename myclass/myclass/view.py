from django.shortcuts import render

import os
import os.path

def index(request):
    rootdir = 'videos/GRE/aw'
   # file_object = open('/record/GRE/aw.txt', 'w')
    courses = []
    for parent, dirnames, filenames in os.walk(rootdir):
       for filename in filenames:

            courses.append(filename)
            #file_object.write(filename + '\n')
  #  file_object.close()

    return render(request, "index.html", {'courses': courses})


def play(request):
    course = request.GET.get('course')
    print(course)
    return render(request, "play.html",locals())