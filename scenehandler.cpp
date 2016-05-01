#include "scenehandler.h"

void SceneHandler::onStatusChanged()
{
    if(m_loader->status() != Qt3DRender::QSceneLoader::Loaded)
        return;

    QVector<Qt3DCore::QEntity *> entities = m_loader->entities();

    if(entities.isEmpty())
        return;

    Qt3DCore::QEntity *root = entities[0];

    walkEntity(root);
}

void SceneHandler::walkEntity(Qt3DCore::QEntity *e, int depth)
{
    Qt3DCore::QNodeList nodes = e->childrenNodes();

    for(int i = 0; i < nodes.count(); ++i)
    {
        Qt3DCore::QNode *node = nodes[i];
        Qt3DCore::QEntity *entity = qobject_cast<Qt3DCore::QEntity *>(node);

        if(entity)
        {
            QString indent;
            indent.fill(' ', depth * 2);
            walkEntity(entity, depth + 1);
        }
    }
}
