; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_37 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_44 () (_ BitVec 32))
(assert
 (let ((?x72926 (bvmul arg0_21 arg1_37)))
(let ((?x70858 (bvmul (_ bv4294967295 32) ?x72926)))
(let ((?x63540 (bvmul arg0_21 arg1_44)))
(let ((?x69107 (bvadd ?x63540 ?x70858)))
(and (distinct ?x69107 (_ bv0 32)) true))))))
(check-sat)
