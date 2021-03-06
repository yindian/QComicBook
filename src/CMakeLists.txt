INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/src/FrameDetect
        ${CMAKE_SOURCE_DIR}/src/Job
	${CMAKE_BINARY_DIR}/src
	${CMAKE_BINARY_DIR}/src/FrameDetect
        ${CMAKE_BINARY_DIR}/src/Job
	${CMAKE_BINARY_DIR}
	${POPPLER_INCLUDE_DIRS}
)

SET(qcomicbook_moc_hdrs
    Debug/DebugController.h
    Debug/ContinuousPageViewDebug.h
    Debug/MemoryDebug.h
	FrameDetect/FrameCache.h
	FrameDetect/FrameDetectThread.h
	Archivers/ArchiversConfiguration.h
	BookmarkManager.h 
	ComicBookCfgDialog.h 
	ComicBookInfo.h
	ComicBookSettings.h 
	ComicMainWindow.h 
	View/FrameView.h
	View/PageViewBase.h 
	View/ContinuousPageView.h
	View/SimplePageView.h
	Sink/ImgSink.h
        Sink/ImgDirSink.h 
	Sink/ImgArchiveSink.h
	LoaderThreadBase.h 
	PageLoaderThread.h
	ThumbnailLoaderThread.h
	GoToPageWidget.h 
        PrinterThread.h
        PrintProgressDialog.h
        RecentFilesMenu.h
	StatusBar.h 
        SystemInfoDialog.h
	ThumbnailsWindow.h 
	ThumbnailsView.h
	ViewProperties.h
        Job/ImageTransformThread.h
)

file (GLOB_RECURSE qcomicbook_hdr *.h *.hpp)
file (GLOB_RECURSE qcomicbook_src *.cpp)
file (GLOB_RECURSE qcomicbook_ui *.ui)

SET(FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${qcomicbook_src}
	${qcomicbook_ui} ${qcomicbook_hdr} PARENT_SCOPE)

qt5_add_resources(qcomicbook_res ../data/qcomicbook.qrc)
qt5_wrap_cpp(qcomicbook_moc_src ${qcomicbook_moc_hdrs})
qt5_wrap_ui(qcomicbook_ui_src ${qcomicbook_ui})

ADD_EXECUTABLE(qcomicbook ${qcomicbook_src} ${qcomicbook_moc_src} ${qcomicbook_ui_src} ${qcomicbook_res})
ADD_DEPENDENCIES(qcomicbook translations)
TARGET_LINK_LIBRARIES(qcomicbook Qt5::Widgets Qt5::PrintSupport)
# Qt5::X11Extras
TARGET_LINK_LIBRARIES(qcomicbook ${POPPLER_LIBRARIES})

INSTALL(TARGETS qcomicbook DESTINATION bin)

