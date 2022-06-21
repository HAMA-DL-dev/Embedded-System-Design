I-Logix-RPY-Archive version 8.5.2 C 2030848
{ IProject 
	- _id = GUID 2633e016-aa61-4c9d-8eda-174af91bb13a;
	- _myState = 8192;
	- _name = "StopwatchProject";
	- _lastID = 1;
	- _UserColors = { IRPYRawContainer 
		- size = 16;
		- value = 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 16777215; 
	}
	- _defaultSubsystem = { ISubsystemHandle 
		- _m2Class = "ISubsystem";
		- _filename = "Default.sbs";
		- _subsystem = "";
		- _class = "";
		- _name = "Default";
		- _id = GUID 9377be44-9803-43f5-bdc8-0b900bf4066b;
	}
	- _component = { IHandle 
		- _m2Class = "IComponent";
		- _filename = "Microsoft.cmp";
		- _subsystem = "";
		- _class = "";
		- _name = "Microsoft";
		- _id = GUID ce8ebe8a-4e7f-49a9-96f9-3f496669580c;
	}
	- Multiplicities = { IRPYRawContainer 
		- size = 4;
		- value = 
		{ IMultiplicityItem 
			- _name = "1";
			- _count = 3;
		}
		{ IMultiplicityItem 
			- _name = "*";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "0,1";
			- _count = -1;
		}
		{ IMultiplicityItem 
			- _name = "1..*";
			- _count = -1;
		}
	}
	- Subsystems = { IRPYRawContainer 
		- size = 3;
		- value = 
		{ ISubsystem 
			- fileName = "Default";
			- _id = GUID 9377be44-9803-43f5-bdc8-0b900bf4066b;
		}
		{ ISubsystem 
			- fileName = "StopwatchPkg";
			- _id = GUID d8c8a7f9-37ca-4336-b611-adc9ad557d7e;
		}
		{ IProfile 
			- fileName = "IDFProfile";
			- _persistAs = "C:\\Rhapsody\\V60_RiC_InterruptDrivenFramework\\V60_RiC_InterruptDrivenFramework_rpy\\IDFProfile";
			- _id = GUID d5ee2130-51e1-4c6c-99cf-62836e1aaf1a;
			- _isReference = 1;
		}
	}
	- Diagrams = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IDiagram 
			- _id = GUID bd84a490-4473-4f39-bc3e-fd953f72a15b;
			- _myState = 8192;
			- _name = "Model1";
			- _lastModifiedTime = "5.25.2022::18:22:20";
			- _graphicChart = { CGIClassChart 
				- _id = GUID 833eabcc-8746-4549-b16c-9faa81d27e9c;
				- m_type = 0;
				- m_pModelObject = { IHandle 
					- _m2Class = "IDiagram";
					- _id = GUID bd84a490-4473-4f39-bc3e-fd953f72a15b;
				}
				- m_pParent = ;
				- m_name = { CGIText 
					- m_str = "";
					- m_style = "Arial" 10 0 0 0 1 ;
					- m_color = { IColor 
						- m_fgColor = 0;
						- m_bgColor = 0;
						- m_bgFlag = 0;
					}
					- m_position = 1 0 0  ;
					- m_nIdent = 0;
					- m_bImplicitSetRectPoints = 0;
					- m_nOrientationCtrlPt = 8;
				}
				- m_drawBehavior = 0;
				- m_bIsPreferencesInitialized = 0;
				- elementList = 1;
				{ CGIClass 
					- _id = GUID f403f53b-6282-4e80-94bf-2180d79c4a59;
					- m_type = 78;
					- m_pModelObject = { IHandle 
						- _m2Class = "IClass";
						- _filename = "Default.sbs";
						- _subsystem = "Default";
						- _class = "";
						- _name = "TopLevel";
						- _id = GUID e63bad99-9b9e-4e83-841a-b9900bc3d4b7;
					}
					- m_pParent = ;
					- m_name = { CGIText 
						- m_str = "TopLevel";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 5;
					}
					- m_drawBehavior = 0;
					- m_bIsPreferencesInitialized = 0;
					- m_AdditionalLabel = { CGIText 
						- m_str = "";
						- m_style = "Arial" 10 0 0 0 1 ;
						- m_color = { IColor 
							- m_fgColor = 0;
							- m_bgColor = 0;
							- m_bgFlag = 0;
						}
						- m_position = 1 0 0  ;
						- m_nIdent = 0;
						- m_bImplicitSetRectPoints = 0;
						- m_nOrientationCtrlPt = 1;
					}
					- m_polygon = 0 ;
					- m_nNameFormat = 0;
					- m_nIsNameFormat = 0;
					- Attrs = { IRPYRawContainer 
						- size = 0;
					}
					- Operations = { IRPYRawContainer 
						- size = 0;
					}
				}
				
				- m_access = 'Z';
				- m_modified = 'N';
				- m_fileVersion = "";
				- m_nModifyDate = 0;
				- m_nCreateDate = 0;
				- m_creator = "";
				- m_bScaleWithZoom = 1;
				- m_arrowStyle = 'S';
				- m_pRoot = GUID f403f53b-6282-4e80-94bf-2180d79c4a59;
				- m_currentLeftTop = 0 0 ;
				- m_currentRightBottom = 0 0 ;
			}
			- _defaultSubsystem = { IHandle 
				- _m2Class = "ISubsystem";
				- _filename = "Default.sbs";
				- _subsystem = "";
				- _class = "";
				- _name = "Default";
				- _id = GUID 9377be44-9803-43f5-bdc8-0b900bf4066b;
			}
		}
	}
	- Components = { IRPYRawContainer 
		- size = 1;
		- value = 
		{ IComponent 
			- fileName = "Microsoft";
			- _id = GUID ce8ebe8a-4e7f-49a9-96f9-3f496669580c;
		}
	}
}

