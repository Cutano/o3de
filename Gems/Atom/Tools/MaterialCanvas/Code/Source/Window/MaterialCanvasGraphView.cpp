/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <Document/MaterialCanvasDocumentRequestBus.h>
#include <Window/MaterialCanvasGraphView.h>

namespace MaterialCanvas
{
    MaterialCanvasGraphView::MaterialCanvasGraphView(
        const AZ::Crc32& toolId,
        const AZ::Uuid& documentId,
        const AtomToolsFramework::GraphViewConfig& graphViewConfig,
        QWidget* parent)
        : AtomToolsFramework::GraphView(toolId, GraphCanvas::GraphId(), graphViewConfig, parent)
        , m_documentId(documentId)
    {
        AtomToolsFramework::AtomToolsDocumentNotificationBus::Handler::BusConnect(m_toolId);
        OnDocumentOpened(m_documentId);
    }

    MaterialCanvasGraphView::~MaterialCanvasGraphView()
    {
        OnDocumentOpened(AZ::Uuid::CreateNull());
        AtomToolsFramework::AtomToolsDocumentNotificationBus::Handler::BusDisconnect();
    }

    void MaterialCanvasGraphView::OnDocumentOpened(const AZ::Uuid& documentId)
    {
        SetActiveGraphId(GraphCanvas::GraphId());
        if (m_documentId == documentId)
        {
            m_activeGraphId = GraphCanvas::GraphId();
            MaterialCanvasDocumentRequestBus::EventResult(m_activeGraphId, documentId, &MaterialCanvasDocumentRequestBus::Events::GetGraphId);
            SetActiveGraphId(m_activeGraphId);
        }
    }

    void MaterialCanvasGraphView::OnDocumentClosed([[maybe_unused]] const AZ::Uuid& documentId)
    {
        if (m_documentId == documentId)
        {
            SetActiveGraphId(GraphCanvas::GraphId());
        }
    }

    void MaterialCanvasGraphView::OnDocumentDestroyed([[maybe_unused]] const AZ::Uuid& documentId)
    {
        if (m_documentId == documentId)
        {
            SetActiveGraphId(GraphCanvas::GraphId());
        }
    }
} // namespace MaterialCanvas

#include <Window/moc_MaterialCanvasGraphView.cpp>
