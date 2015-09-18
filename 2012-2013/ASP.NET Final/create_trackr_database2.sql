IF DB_ID('Final_Trackr') IS NOT NULL
	DROP DATABASE Final_Trackr
	
CREATE DATABASE Final_Trackr
GO

USE [Final_Trackr]
GO
/****** Object:  Table [dbo].[Projects]    Script Date: 4/29/2013 7:24:02 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Projects](
	[ProjectID] [int] NOT NULL,
	[ProjectName] [varchar](50) NOT NULL,
 CONSTRAINT [PK_Projects] PRIMARY KEY CLUSTERED 
(
	[ProjectID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Projects] ([ProjectID], [ProjectName]) VALUES (1, N'Legends of the Dead')
INSERT [dbo].[Projects] ([ProjectID], [ProjectName]) VALUES (2, N'Project: Shade')
INSERT [dbo].[Projects] ([ProjectID], [ProjectName]) VALUES (3, N'Trackr')
INSERT [dbo].[Projects] ([ProjectID], [ProjectName]) VALUES (4, N'Untitled JRPG')
/****** Object:  Table [dbo].[Tasks]    Script Date: 4/29/2013 7:24:02 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Tasks](
	[TaskID] [int] NOT NULL,
	[ProjectID] [int] NOT NULL,
	[TaskTitle] [varchar](50) NOT NULL,
	[TaskDescription] [varchar](max) NOT NULL,
	[DateOpened] [datetime] NOT NULL,
	[DateClosed] [datetime] NULL,
 CONSTRAINT [PK_Tasks] PRIMARY KEY CLUSTERED 
(
	[TaskID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0001, 1, N'Perlin Noise', N'Perfect Perlin Noise Generation', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0002, 1, N'Map Generation', N'Finish Map Generation', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0003, 2, N'Fix Camera System', N'Force Camera To Follow Player', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0004, 1, N'Fix Camera System', N'Force Camera To Follow Player', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0005, 1, N'Add Art', N'Add All Art Assets', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0006, 2, N'Story', N'Come Up With Storylines', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0007, 3, N'WCF', N'Complete WCF', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0008, 3, N'Turn In', N'TTurn In To Prof. Flemming', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0009, 4, N'Develop', N'Come Up With Game Idea', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0010, 4, N'Title', N'Come Up with Title', CAST(0x00009AEB00000000 AS DateTime), NULL)
INSERT [dbo].[Tasks] ([TaskID], [ProjectID], [TaskTitle], [TaskDescription], [DateOpened], [DateClosed]) VALUES (0011, 4, N'Something', N'Come Up With Something Relevant', CAST(0x00009AEB00000000 AS DateTime), NULL)
GO
SET ANSI_PADDING OFF
GO