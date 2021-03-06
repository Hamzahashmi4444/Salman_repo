from AccessControl import ClassSecurityInfo

from Products.naayaUpdater.updates import UpdateScript

class SetContributor(UpdateScript):
    """ Set contributor if None """
    title = 'Set contributor if None'
    creation_date = 'May 24, 2013'
    authors = ['Valentin Dumitru']
    description = 'Updates the contributor from the owner role if contributor is None or for Naaya Survey and Forum if the property does not exist. If the contributor is saved as unicode, it is converted to str.'
    security = ClassSecurityInfo()

    security.declarePrivate('_update')
    def _update(self, portal):
        portal_catalog = portal.getCatalogTool()
        for brain in portal_catalog():
            item = brain.getObject()
            if not hasattr(item.aq_base, 'contributor'):
                if item.meta_type not in ['Naaya Forum', 'Naaya Mega Survey']:
                    continue
            elif item.contributor is not None:
                if isinstance(item.contributor, unicode):
                    item.contributor = str(item.contributor)
                    self.log.debug('%s contributor changed from unicode to str'
                        % item.absolute_url())
                continue
            self.log.debug('%s has no "contributor"' % item.absolute_url())
            item.contributor = str(item.getOwner().name)
            self.log.debug('new owner is %s' % item.contributor)
        return True
