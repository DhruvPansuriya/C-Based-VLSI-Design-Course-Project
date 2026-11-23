; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x484752 (bvmul arg0_6 arg0_9)))
(let ((?x12049 (bvmul (_ bv4294967295 32) ?x484752)))
(let ((?x479968 (bvmul arg0_6 arg0_6)))
(let ((?x417125 (bvadd ?x479968 ?x12049)))
(and (distinct ?x417125 (_ bv0 32)) true))))))
(check-sat)
