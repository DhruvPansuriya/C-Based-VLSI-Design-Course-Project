; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let ((?x481478 (concat ((_ extract 28 0) arg0) (_ bv0 3))))
(let ((?x556992 (bvmul (_ bv4294967295 32) ?x481478)))
(let ((?x482605 (bvmul (_ bv8 32) arg0)))
(let (($x484365 (and (distinct (_ bv0 32) (bvadd ?x482605 ?x556992)) true)))
(let (($x563729 (and true true (or $x484365))))
(or $x563729)))))))
(check-sat)
