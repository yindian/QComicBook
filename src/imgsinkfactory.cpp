/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005 Pawel Stolowski <yogin@linux.bydg.org>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#include "imgsinkfactory.h"
#include "imgdirsink.h"
#include "imgarchivesink.h"
#include <qstring.h>
#include <qfileinfo.h>

ImgSinkFactory::ImgSinkFactory()
{
}

ImgSinkFactory::~ImgSinkFactory()
{
}

ImgSinkFactory& ImgSinkFactory::instance()
{
	static ImgSinkFactory f;
	return f;
}

ImgSink* ImgSinkFactory::createImgSink(SinkType s)
{
	if (s == ArchiveSink)
		return new ImgArchiveSink();
	if (s == DirSink)
		return new ImgDirSink();
	return NULL;
}

ImgSink* ImgSinkFactory::createImgSink(const QString &path)
{
	const QFileInfo finfo(path);
	if (finfo.isDir())
		return createImgSink(DirSink);
	else
		return createImgSink(ArchiveSink);
}
