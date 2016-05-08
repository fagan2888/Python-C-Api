#!/usr/bin/python

import config

class server:
	def __init__(self, i="", p=0):
		self.ip = i
		self.port = p

class plugin:
	def __init__(self, i="", p="", t=""):
		self.interpreter = i
		self.program = p
		self.type = t

class setup:
	def __init__(self):
		self.server = server()
		self.plugins = []

	def addPlugin(p):
		self.plugins.append(p)

def get_document():
	string_xml = open('config.xml').read()
	configuration = config.CreateFromDocument(string_xml)

	return configuration

def extract_server():
	cfg = get_document()
	ip_addr = cfg.server.ip
	port = cfg.server.port
	s = server(ip_addr, port)

	ret = "{0}:{1}".format(s.ip,s.port)

	return 	ret.replace("\"",'')

def getVal():
	return "plugin"

def extract_plugin(number):
	return ""
	




